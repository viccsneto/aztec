#include <iostream>
#include <tolua.h>
#include <algorithm>
#include <omp.h>
#include <GL/glew.h>
#include <clocale>

#include "Mouse.h"
#include "GameCanvas.h"
#include "GameEngine.h"
#include "Config.h"
#include "EventDispatcher.h"
#include "Keyboard.h"
#include "DebugDraw.h"
#include <electron_bind.h>
#include <luaelectron_bind.h>

#ifdef _DEBUG
#define LOG_FILE "log_debug.txt"
#else
#define LOG_FILE "log_release.txt"
#endif

#define CONFIG_FILE "Config.ini"
#define LUA_SUBSYSTEM_FILE "LuaSubSystem/LuaSubSystem.Lua"
#define ALWAYS_DRAW true

namespace Aztec {
  GameEngine *GameEngine::_instance = NULL;
  GameCanvas *GameEngine::_canvas   = NULL;
  //PropertyList GameEngine::Arguments;
  stack<GameStateController *> GameEngine::_loadingGameStates;
  lua_State *                  GameEngine::LUA_STATE = luaL_newstate();

  static void scroll_callback(GLFWwindow *window, double x, double y)
  {
    GameEngine::getInstance()->getMouse()->scrolled(x, y);
  }

  static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
  {
    auto keyboard = GameEngine::getInstance()->getKeyboard();
    
    bool shift = keyboard->isShiftPressed();
    bool control = keyboard->isControlPressed();
    bool alt = keyboard->isAltPressed();
    bool repeating = action == GLFW_REPEAT;

    if (action == GLFW_PRESS || repeating) {
      GameEngine::getInstance()->getKeyboard()->keyPressed(key);
      EventDispatcher::doKeyDown(key);
      if (key == GLFW_KEY_PERIOD || key == GLFW_KEY_MINUS)
        return;
      keyboard->putOnKeyboardBuffer(Keyboard::Key(key, false, false, control, shift, alt, repeating));
    }
    else if (action == GLFW_RELEASE) {
      GameEngine::getInstance()->getKeyboard()->keyReleased(key);
      EventDispatcher::doKeyUp(key);
      GameEngine::getInstance()->getKeyboard()->putOnKeyboardBuffer(Keyboard::Key(key, false, true, control, shift, alt, repeating));
    }
  }

  static void character_callback(GLFWwindow *window, unsigned int codepoint)
  {
    auto keyboard = GameEngine::getInstance()->getKeyboard();
    bool shift = keyboard->isShiftPressed();
    bool control = keyboard->isControlPressed();
    bool alt = keyboard->isAltPressed();
    bool repeating = false;

    GameEngine::getInstance()->getKeyboard()->putOnKeyboardBuffer(Keyboard::Key(codepoint, true, false, control, shift, alt, repeating));
    GameEngine::getInstance()->getKeyboard()->putOnKeyboardBuffer(Keyboard::Key(codepoint, true, true, control, shift, alt, repeating));
  }

  static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
  {
    GameEngine::getInstance()->getMouse()->moved(xpos, ypos);
  }

  void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
  {
    if (action == GLFW_PRESS) {
      GameEngine::getInstance()->getMouse()->buttonPressed(button);
      EventDispatcher::doMouseDown(button);
    }
    else if (action == GLFW_RELEASE) {
      GameEngine::getInstance()->getMouse()->buttonReleased(button);
      EventDispatcher::doMouseUp(button);
    }
  }

  void GameEngine::Lua_Init()
  {
    //Load Lua Standard Libs
    luaL_openlibs(GameEngine::LUA_STATE);

    //Lua Electron
    luaopen_luaelectron(GameEngine::LUA_STATE);

    // Lua Aztec Binding
    luaopen_Aztec_Lua_Bind(GameEngine::LUA_STATE);

    //Load config parameters.
    if (luaL_dofile(GameEngine::LUA_STATE, CONFIG_FILE) != 0) {
      registerError("Error during \"%s\" load: %s - <%s [%d]>", CONFIG_FILE, lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
      exit(1);
    }

    //Load the Aztec Lua Sub System(Aztec functionalities that are implemented in Lua and can interact easily with the user scripts)
    if (luaL_dofile(GameEngine::LUA_STATE, LUA_SUBSYSTEM_FILE) != 0) {
      registerError("Couldn't initialize the Lua Sub-System: %s - <%s %d>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
      exit(2);
    }
  }

  GameEngine::GameEngine()
  {
    Arguments = new PropertyList();
    Lua_Init();


    // member variables initializations

    _canvas = new GameCanvas(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT);

    //If using GLFW, register the callback functions

    glfwSetKeyCallback(_canvas->getWindow(), key_callback);
    glfwSetCharCallback(_canvas->getWindow(), character_callback);
    glfwSetScrollCallback(_canvas->getWindow(), scroll_callback);

    glfwSetCursorPosCallback(_canvas->getWindow(), cursor_position_callback);
    glfwSetMouseButtonCallback(_canvas->getWindow(), mouse_button_callback);

    //I/O Devices
    _keyboard = new Keyboard();
    _mouse    = new Mouse();

    _currentTime        = glfwGetTime();
    _lastTime           = _currentTime;
    _elapsedTime        = Config::MAX_ELAPSEDTIME;
    _drawingElapsedTime = Config::MAX_ELAPSEDTIME;
    _currGameState      = NULL;
    _nextGameState      = NULL;

    //The engine is not running yet. Must call run method to start it
    _engineRunning = false;
  }

  void GameEngine::freeInstance()
  {
    if (_instance != NULL) {
      delete _instance;
      _instance = NULL;
    }
  }

  GameStateController *GameEngine::getContextGameState()
  {
    if (!_loadingGameStates.empty()) {
      return _loadingGameStates.top();
    }

    return _currGameState;
  }

  GameEngine::~GameEngine()
  {
  }

  GameCanvas *GameEngine::getGameCanvas()
  {
    return _canvas;
  }

  void GameEngine::run(GameStateController *gs)
  {
    if (!_engineRunning) {
      _currGameState = gs;
      run();
    }
    else {
      _nextGameState = gs;
    }
  }

  void GameEngine::requestShutdown()
  {
    _engineRunning = false;
  }

  double GameEngine::getTrueCurrentTime()
  {
    return omp_get_wtime() - _startTime;
  }

  GameStateController *GameEngine::getCurrentGameState()
  {
    return _currGameState;
  }

  void GameEngine::run()
  {
    // if there is no current game state, don't do anything.
    if (_currGameState == NULL) {
      return;
    }
    //Sets the engine state as running
    _engineRunning = true;

    _currGameState->start();
    _currentTime = glfwGetTime();
    _startTime   = omp_get_wtime();
    _lastTime    = _currentTime;

    //Treat the events
    TreatEvents();
    //MainLoop
    while (_engineRunning) {
      //calculate the delta time since last frame
      _currentTime = glfwGetTime();
      _elapsedTime = _currentTime - _lastTime;
      if (_elapsedTime > Config::MAX_ELAPSEDTIME) {
        _elapsedTime = Config::MAX_ELAPSEDTIME;
        _currentTime = _lastTime + Config::MAX_ELAPSEDTIME;
        glfwSetTime(_currentTime);
      }

      _drawingElapsedTime += _elapsedTime;
      bool should_draw = ALWAYS_DRAW || _drawingElapsedTime >= Config::MAX_ELAPSEDTIME;

      if (should_draw) {
        //Begin the rendering cycle
        _canvas->beginRendering();
      }

      // if there's another state in line, make him the current game state.
      while (_nextGameState != NULL) {
        _currGameState->stop();
        _currGameState = _nextGameState;
        _nextGameState = NULL;

        _currGameState->start();
      }

      TreatEvents();
      //Dispatch events to the interested objects
      EventDispatcher::dispatchMouseEvents();

      //removes objects marked to be removed from previous lists
      ResourceManager::removeObjects();
      //Trully destroys objects marked to be destroyed during the last step
      ResourceManager::destroyObjects();

      _currGameState->step();

      //Draw the current frame(iterates over each GameObject added to the GameState)
      if (should_draw) {
        _currGameState->draw();

        //Draws physics debug information
        if (Config::DEBUG_DRAW) {
          glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

          _currGameState->getWorld()->DrawDebugData();
        }
        //Ends the rendering cycle
        _canvas->endRendering();
        _drawingElapsedTime = 0;
      }

      _lastTime = _currentTime;
    }

    shutdown();
  }

  void GameEngine::registerOnLog(char *strMessage, char *strTime, char *msgType, va_list args)
  {
    FILE *stream;

    stream = fopen(LOG_FILE, "a");
    if (stream == NULL) {
      fprintf(stderr, "[ERROR]: Couldn't register log on %s file.\n", LOG_FILE);
      return;
    }

    fprintf(stream, "[%s] %s:", msgType, strTime);

    vfprintf(stream, strMessage, args);
    fprintf(stream, "\n");
    fclose(stream);
  }

  void GameEngine::registerError(char *strMessage, ...)
  {
    FILE *stream;

    stream = stderr;

    time_t     rawtime;
    struct tm *timeinfo;
    char       buffer[32];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 32, "%d/%m/%Y %H:%M:%S", timeinfo);
    fprintf(stream, "[ERROR] %s:", buffer);

    va_list args;
    va_start(args, strMessage);
    vfprintf(stream, strMessage, args);
    registerOnLog(strMessage, buffer, "ERROR", args);
    va_end(args);
    fprintf(stream, "\n");
    requestShutdown();
  }

  void GameEngine::registerWarning(char *strMessage, ...)
  {
    FILE *stream;
    stream = stderr;
    time_t     rawtime;
    struct tm *timeinfo;
    char       buffer[32];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 32, "%d/%m/%Y %H:%M:%S", timeinfo);
    fprintf(stream, "[WARNING] %s:", buffer);

    va_list args;
    va_start(args, strMessage);
    vfprintf(stream, strMessage, args);
    registerOnLog(strMessage, buffer, "WARNING", args);
    va_end(args);
    fprintf(stream, "\n");
  }

  void GameEngine::TreatEvents()
  {
    getMouse()->Reset();

    glfwPollEvents();
    if (glfwWindowShouldClose(_canvas->getWindow())) {
      requestShutdown();
    }
  }

  Keyboard *GameEngine::getKeyboard()
  {
    return _keyboard;
  }

  Mouse *GameEngine::getMouse()
  {
    return _mouse;
  }

  double GameEngine::getElapsedTime()
  {
    return _elapsedTime;
  }

  double GameEngine::getTrueElapsedTime()
  {
    return glfwGetTime() - _lastTime;
  }

  double GameEngine::getCurrentTime()
  {
    return _currentTime;
  }

  void GameEngine::beginLoadGameState(GameStateController *state)
  {
    if (state != NULL) {
      _loadingGameStates.push(state);
    }
  }

  void GameEngine::endLoadGameState(GameStateController *state)
  {
    if (state != NULL) {
      _loadingGameStates.pop();
    }
  }

  void GameEngine::shutdown()
  {
    ResourceManager::removeObjects();
    ResourceManager::destroyObjects();
    ResourceManager::freeAll();
    delete _canvas;
    delete _mouse;
    delete _keyboard;
    delete _nextGameState;
    delete _currGameState;
  }

  GameEngine *GameEngine::Initialize()
  {

    std::setlocale(LC_ALL, "pt_BR.UTF-8");
    if (!_instance)
      _instance = new GameEngine();

    return _instance;
  }

  bool GameEngine::isRunning()
  {
    return _engineRunning;
  }

  void GameEngine::SetOffscreenRenderer(WebBrowser *browser)
  {
    getGameCanvas()->SetOffscreenRenderer(browser);
  }

  GameEngine *GameEngine::getInstance()
  {
    return _instance;
  }
} // namespace Aztec