#pragma once
#if 0 //_DEBUG
#define MAIN_LUA_FILE "scripts/debug.Lua"
#else
#define MAIN_LUA_FILE "scripts/main.Lua"
#endif

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <lua.hpp>
#include <time.h>
#include "GameCanvas.h"
#include "GameObject.h"
#include "GameStateController.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "PropertyList.h"
#include "Sprite.h"
#include "ResourceManager.h"
#include "Aztec_Lua_Bind.h"
#include "DebugDraw.h"
#include "WebBrowser.h"

/**
* Aztec Generic Namespace
*/
namespace Aztec {
  /**
  * GameEngine
  *
  * The Aztec engine class itself.
  *
  * \author Vicente Neto
  *
  */
  class GameEngine {
  public:
    void SetOffscreenRenderer(WebBrowser *browser);
    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * @return The current instance of the Game Engine. (Provides singleton behaviour)
    */
    static GameEngine *getInstance();

    /**
    * Initializes the singleton instance of the GameEngine and handles the multi-process behavior of
    * Chromium Embedded Framework
    *
    * @return A pointer to the GameEngine singleton or null if it is not the main process but a CEF sub-process
    */
    static GameEngine *Initialize();


    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * @return A pointer to the command line PropertyList of arguments 
    */
    PropertyList *Arguments;

    /**
    * Indicates if the engine is running
    */
    bool isRunning();

    /**
    * Deletes the singleton instance of the engine
    */
    static void freeInstance();

    /**
    * getGameCanvas
    *
    * @return the reference to the canvas used by the engine.
    */
    static GameCanvas *getGameCanvas();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Tells the engine to shutdown. The game will finish the loop and then
    * get out of it.
    */
    void requestShutdown();

    /**
    * Starts the game loop.
    */
    void run();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Starts the game loop.
    */
    void run(GameStateController *gs);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * @return The reference to the Keyboard managed by the engine.
    */
    Keyboard *getKeyboard();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * @return The reference to the mouse managed by the engine.
    */
    Mouse *getMouse();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * returns how much time has passed since the last game loop was executed in
    * seconds.
    *
    * @return double value with the amount of milliseconds passed since the last
    * game loop was executed.
    */
    double getElapsedTime();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * returns how much time has passed since the last game loop was executed in
    * seconds.
    *
    * @return double value with the amount of milliseconds passed since the last
    * game loop was executed.
    */
    double getTrueElapsedTime();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * returns how much time has passed since the system initialization in
    * milliseconds.
    *
    * @return long value with the amount of milliseconds passed since initialization
    * of the system
    */

    double getCurrentTime();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * returns how much time has passed since the system initialization in
    * milliseconds.
    *
    * @return long value with the amount of milliseconds passed since initialization
    * of the system
    */

    double getTrueCurrentTime();

    /**
    * LUA_STATE
    *
    * The Global LUA_STATE reference that must be used when loading additional Lua libraries, executing Lua files, etc
    */
    static lua_State *LUA_STATE;

    /**
    *
    * Gets the GameState that must be considered when creating new GameObjects.
    * By context, it maybe the running GameState or some GameState that are loading at the current time
    *
    * @return A pointer to the contextual GameStateController 
    */
    GameStateController *getContextGameState();

    /**
    * Gets the current running GameState.
    *
    * @return A pointer to the current GameStateController
    */
    GameStateController *getCurrentGameState();

    /**
    * Puts a GameStateController object in the stack of loading GameStates.    
    * This stack will be used to associate new GameObjects within the contextual GameStateController(i.e.: New game object will be associated to the loading GameStateController instead of the active GameStateController)
    *
    * @param state A pointer to the GameStateController that will be pushed onto the stack
    */
    void beginLoadGameState(GameStateController *state);

    /**
    * Removes the GameStateController object from the stack of loading GameStates.
    *
    * @param state A pointer to the GameStateController that will be popped from the stack
    */
    void endLoadGameState(GameStateController *state);

    /**    
    * Notifies the user that a warning occurs and write the message to the log.
    *
    * @param strMessage The warning message
    * @param ... Variable list of arguments that will be formatted to the message
    */
    void registerWarning(char *strMessage, ...);

    /**
    * Notifies the user that an error occurs and write the message to the log.
    *
    * @param strMessage The error message
    * @param ... Variable list of arguments that will be formatted to the message
    */
    void registerError(char *strMessage, ...);

    /**
    * registerOnLog
    *
    * Write a message to the log.
    */
    void registerOnLog(char *strMessage, char *strTime, char *msgType, va_list args);

  private:
    void shutdown();
    /**
    * Canvas
    *
    * Canvas where everthing will be drawn on.
    */
    static GameCanvas *_canvas;

    /**
    * Keyboard
    *
    * keyboard events handler.
    */
    Keyboard *_keyboard;

    /**
    * Mouse
    *
    * mouse events handler.
    */
    Mouse *_mouse;

    /**
    * Last Time
    *
    * keeps the last time the game loop was executed.
    */
    double _lastTime;

    /**
    * Current Time
    *
    * How much time has passed since the initialization
    */

    double _currentTime;

    /**
    * Start Time
    *
    * t0 of the running loop
    */
    double _startTime;

    /**
    * Elapsed Time
    *
    * keeps how much time has passed since the last game loop was executed
    */
    double _elapsedTime;

    double _drawingElapsedTime;

    /**
    * Engine Running
    *
    * tells if the engine is running
    */
    bool _engineRunning;

    /**
    * Current Game State
    *
    * keeps a pointer to the current game state.
    */
    GameStateController *_currGameState;

    /**
    * _loadingGameStates
    *
    * a stack of loading GameStates (it is necessary to make the connection between loading game objects with the correct game state
    */
    static stack<GameStateController *> _loadingGameStates;

    /**
    * Next Game State
    *
    * keeps a pointer to the game state that will be loaded at the next loop.
    */
    GameStateController *_nextGameState;

    /**
    * Instance
    *
    * Keeps the singleton instance of the Engine.
    */
    static GameEngine *_instance;

    /**
    * Constructor
    *
    * GameEngine is a singleton. It must be instantiated/accessed through the getInstance() static method.
    */
    GameEngine();

    /**
    * Destructor
    *
    * GameEngine is a singleton. It's instance can be destroyed through the freeInstance() static method.
    */
    ~GameEngine();

    /**
    * TreatEvents
    *
    * Treat the SDL events at every iteration of the main game loop
    */
    void TreatEvents();

    /**
    * Lua_Init
    * Initialize the Lua Sub Systems
    */
    void Lua_Init();
  };
} // namespace Aztec
