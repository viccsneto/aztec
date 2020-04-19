#include "WebBrowser.h"
#include "GameEngine.h"
#include "ResourceManager.h"
#include "Shader.h"
#include "json.hpp"

#define MOUSE_DOUBLE_CLICK_INTERVAL 0.150f
namespace Aztec
{
  WebBrowser::WebBrowser(const char *url, int width, int height, bool transparent)
  {
    Initialize(url, width, height, transparent);
  }

  WebBrowser::WebBrowser(const char *url, int width, int height)
  {
    Initialize(url, width, height, false);
  }

  void WebBrowser::Initialize(const char *url, int width, int height, bool transparent)
  {
    _className.assign("WebBrowser");
    m_last_click_time = 0;
    m_was_previously_focused = false;
    m_always_focused = false;
    m_has_focus = false;
    m_painted = false;
    m_width = width;
    m_height = height;
    m_texture_message= nullptr;

    RESTexture *texture = ResourceManager::createTexture(width, height, NULL);
    m_texture = new Texture(texture, GL_RGBA, GL_BGRA);
    m_plane = new Plane(Shader::getDefaultShader(), width, height, m_texture);
    m_browser = new ElectronBrowser((std::string("--url \"") + url +"\"").c_str());
    m_browser->RemoveListener("execute");

    m_browser->AddListener("execute", [&](std::shared_ptr<Petunia::Message> message) {
      if (GameEngine::LUA_STATE) {
        lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
        lua_getfield(GameEngine::LUA_STATE, -1, "Execute");
        tolua_pushusertype(GameEngine::LUA_STATE, this, "WebBrowser");
        tolua_pushstring(GameEngine::LUA_STATE, message->GetData()->c_str());

        if (lua_pcall(GameEngine::LUA_STATE, 2, 0, 0) != 0) {
          printf("WebBrowser:execute failed: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
        }

        lua_pop(GameEngine::LUA_STATE, 1);
      }
    });

    m_browser->AddListener("paint", [&](std::shared_ptr<Petunia::Message> message) {
      std::lock_guard<std::mutex> lock(m_texture_mutex);
      m_texture_message = message;
    });

    m_browser->SendMessage(std::make_shared<Petunia::Message>("ready", "ready"));
    m_sensor = new Sensor();
    m_sensor->setPivot(_pivot.x, _pivot.y);
    m_sensor->createFixture(width, height);
    m_sensor->setFilterData(ContactFilter::FilterFlags::Sensor | ContactFilter::FilterFlags::Renderable,
                            ContactFilter::FilterFlags::Camera | ContactFilter::FilterFlags::Mouse | ContactFilter::FilterFlags::Sensor);
    addGameObject(m_sensor);
  }


  void WebBrowser::Navigate(const char *url)
  {
    m_browser->Execute((std::string("navigate(") + url + ")").c_str());
  }

  void WebBrowser::GoBack()
  {
    // m_browser->GoBack();
  }

  void WebBrowser::GoForward()
  {
    // m_browser->GoForward();
  }

  void WebBrowser::Refresh()
  {
    // m_browser->Reload();
  }

  void WebBrowser::Stop()
  {
    // m_browser->StopLoad();
  }

  bool WebBrowser::isLoading()
  {
    // return m_browser->IsLoading();
    return false;
  }

  void WebBrowser::ExecuteScript(const char *script)
  {
    m_browser->Execute(script);
  }

  void WebBrowser::ExecuteCallBackScript(const char *script)
  {
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "ExecuteCallBackScript");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "WebBrowser");
    tolua_pushstring(GameEngine::LUA_STATE, script);

    if (lua_pcall(GameEngine::LUA_STATE, 2, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA ExecuteCallBackScript: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }
    lua_pop(GameEngine::LUA_STATE, 1);
  }

  WebBrowser::~WebBrowser()
  {
    delete m_browser;
    delete m_plane;
    delete m_texture;
    GLFWcursor *glfw_cursor = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);

    glfwSetCursor(GameEngine::getInstance()->getGameCanvas()->getWindow(), glfw_cursor);
  }


  void WebBrowser::step()
  {

    GameObject::step();
    if (!Enabled) {
      return;
    }

    UpdateTexture();
    
    HandleMouseInputEvents();

    if (hasFocus()) {
      Focus();
    }

    bool extended = true;
    int modifiers = GameEngine::getInstance()->getKeyboard()->getModifiers(extended);

    while (GameEngine::getInstance()->getKeyboard()->bufferLength() > 0) {
      Keyboard::Key key = GameEngine::getInstance()->getKeyboard()->readVKBuffer();

      bool ctrl_pressed = (modifiers & Aztec::Keyboard::KEY_LCTRL) == Aztec::Keyboard::KEY_LCTRL || (modifiers & Aztec::Keyboard::KEY_RCTRL) == Aztec::Keyboard::KEY_RCTRL;
      bool shift_pressed = (modifiers & Aztec::Keyboard::KEY_LSHIFT) == Aztec::Keyboard::KEY_LSHIFT || (modifiers & Aztec::Keyboard::KEY_RSHIFT) == Aztec::Keyboard::KEY_RSHIFT;
      bool alt_pressed = (modifiers & Aztec::Keyboard::KEY_LALT) == Aztec::Keyboard::KEY_LALT || (modifiers & Aztec::Keyboard::KEY_RALT) == Aztec::Keyboard::KEY_RALT;
      std::string key_code = TranslateKeyCode(key.code);
     
      nlohmann::json key_event{
        {"keyCode", key_code },
        {"ctrlKey", ctrl_pressed},
        {"shiftKey", shift_pressed},
        {"altKey", alt_pressed},
      };
            
      if (key.release_event) {
        key_event["type"] = "keyUp";
      }
      else {
        if (key.is_character) {          
          key_event["type"] = "char";          
        }
        else {
          key_event["type"] = "keyDown";
        }
      }

      std::string script =
        "mainWindow.webContents.sendInputEvent(" +
        key_event.dump() +
        ");";

      std::cout << "Executing: " << script << std::endl;
      m_browser->Execute(script);

     
    }      
  }

  void WebBrowser::draw()
  {
    std::lock_guard<std::mutex> lock(m_texture_mutex);
    if (!Visible) {
      return;
    }

    beginClipRect();

    if (m_painted) {
      int xPivotInverter = 1;
      int yPivotInverter = 1;
      float xRotation = 0;
      float yRotation = 0;

      m_plane->setPivot(_pivot.x.rawget() * _globalTransform.scale.x * xPivotInverter, _pivot.y.rawget() * _globalTransform.scale.y * yPivotInverter, 0);


      m_plane->setTranslation(_globalTransform.position.x, _globalTransform.position.y, 0);
      m_plane->setScale(_globalTransform.scale.x, _globalTransform.scale.y, 1.0f);
      m_plane->setPostRotation(xRotation, yRotation, 0);
      m_plane->setRotation(0, 0, -_globalTransform.rotation);

      m_plane->getShader()->SetUniform("texCoordX", 0);
      m_plane->getShader()->SetUniform("texCoordY", 0);
      m_plane->getShader()->SetUniform("time", GameEngine::getInstance()->getCurrentTime());
      m_plane->Draw();
    }
    drawChildren();
    endClipRect();
    auto message = std::make_shared<Petunia::Message>("ready", "ready");
    //message->SetOverwriteMode(true);
    m_browser->SendMessage(message);
  }

  void WebBrowser::setAlwaysFocused(bool value)
  {
    //    m_browser->GetHost()->SetFocus(value||mouseOver);
    if (!m_always_focused)
      m_was_previously_focused = false;

    m_always_focused = value;
  }

  bool WebBrowser::getAlwaysFocused()
  {
    return m_always_focused;
  }

  void WebBrowser::UpdateTexture()
  {
    std::lock_guard<std::mutex> lock(m_texture_mutex);
    if (m_texture_message) {
      m_painted = true;
      m_texture->UpdateTexture(m_texture_message->GetData()->data());
      m_texture_message = nullptr;
    }
  }

  Plane *WebBrowser::getPlane()
  {
    return m_plane;
  }

  Shader *WebBrowser::getShader()
  {
    return m_plane->getShader();
  }

  Shader *WebBrowser::setShader(Shader *shader)
  {
    return m_plane->setShader(shader);
  }

  void WebBrowser::HandleMouseInputEvents()
  {
    int x = GameEngine::getInstance()->getMouse()->getPosX() - getGlobalTransform().position.x;
    int y = GameEngine::getInstance()->getMouse()->getPosY() - getGlobalTransform().position.y;
    
    if (mouseOver) {
      HandleMouseClicks(x, y);
      HandleMouseMovement(x, y);
      HandleMouseWheel();

    }
    else {
      Blur();

    }
  }

  void WebBrowser::HandleMouseClicks(int x, int y)
  {
    if (GameEngine::getInstance()->getMouse()->LeftButtonJustPressed()) {
      if (!m_was_previously_focused) {
        GameEngine::getInstance()->getKeyboard()->cleanBuffer();
        Focus();

      }

      int click_count = 1;
      double click_interval = (GameEngine::getInstance()->getCurrentTime() - m_last_click_time);
      if (click_interval < MOUSE_DOUBLE_CLICK_INTERVAL) {
        click_count++;
      }

      m_browser->Execute(
        "mainWindow.webContents.sendInputEvent(" +
        nlohmann::json{
          {"type", "mouseDown"},
          {"button", "left"},
          {"x", x},
          {"y", y},
          {"clickCount", click_count},
        }.dump() +
        ");"
      );
    }

    if (GameEngine::getInstance()->getMouse()->LeftButtonJustReleased()) {
      m_browser->Execute(
        "mainWindow.webContents.sendInputEvent(" +
        nlohmann::json{
          {"type", "mouseUp"},
          {"button", "left"},
          {"x", x},
          {"y", y}
        }.dump() +
        ");"
      );
      m_last_click_time = GameEngine::getInstance()->getCurrentTime();
    }

    if (GameEngine::getInstance()->getMouse()->RightButtonJustPressed()) {      
      m_browser->Execute(
        "mainWindow.webContents.sendInputEvent(" +
        nlohmann::json{
          {"type", "mouseDown"},
          {"button", "right"},
          {"x", x},
          {"y", y},
          
        }.dump() +
        ");"
      );
    }

    if (GameEngine::getInstance()->getMouse()->RightButtonJustReleased()) {
      m_browser->Execute(
        "mainWindow.webContents.sendInputEvent(" +
        nlohmann::json{
          {"type", "mouseUp"},
          {"button", "right"},
          {"x", x},
          {"y", y}
        }.dump() +
        ");"
      );
      m_last_click_time = GameEngine::getInstance()->getCurrentTime();
    }

    if (GameEngine::getInstance()->getMouse()->MiddleButtonJustPressed()) {
      m_browser->Execute(
        "mainWindow.webContents.sendInputEvent(" +
        nlohmann::json{
          {"type", "mouseDown"},
          {"button", "middle"},
          {"x", x},
          {"y", y},
          {"clickCount", 1},
        }.dump() +
        ");"
      );
    }

    if (GameEngine::getInstance()->getMouse()->MiddleButtonJustReleased()) {
      m_browser->Execute(
        "mainWindow.webContents.sendInputEvent(" +
        nlohmann::json{
          {"type", "mouseUp"},
          {"button", "middle"},
          {"x", x},
          {"y", y}
        }.dump() +
        ");"
      );
      m_last_click_time = GameEngine::getInstance()->getCurrentTime();
    }
  }

  void WebBrowser::Focus()
  {
    m_browser->Execute("mainWindow.focus();");
    m_has_focus = true;
  }

  bool WebBrowser::hasFocus()
  {
    return m_has_focus || m_always_focused;
  }

  void WebBrowser::HandleMouseMovement(int x, int y)
  {
    if (GameEngine::getInstance()->getMouse()->hasMovement) {
      m_browser->Execute(
        "mainWindow.webContents.sendInputEvent(" +
        nlohmann::json{
          {"type", "mouseMove"},
          {"x", x},
          {"y", y}
        }.dump() +
        ");"
      );
    }
  }

  void WebBrowser::HandleMouseWheel()
  {
    if (GameEngine::getInstance()->getMouse()->hasWheel) {
      m_browser->Execute(
        "mainWindow.webContents.sendInputEvent(" +
        nlohmann::json{
          {"type", "mouseWheel"},
          {"x", 0},
          {"y", 0},
          {"deltaX", GameEngine::getInstance()->getMouse()->getScrolledX()},
          {"deltaY", GameEngine::getInstance()->getMouse()->getScrolledY()}
        }.dump() +
        ");"
      );
    }
  }

  void WebBrowser::Blur()
  {
    if (m_has_focus) {
      if (!m_always_focused) {
        m_browser->Execute("mainWindow.blur();");
        m_was_previously_focused = false;
        m_has_focus = false;
      }
    }
  }

  std::string WebBrowser::TranslateKeyCode(int code)
  {
    std::string key_code = "";
    bool is_alphanumeric = code >= 0 && code <= 255 && std::isalnum(code);

    if (is_alphanumeric) {
      key_code = " ";
      key_code[0] = code;
    }
    else {
      if (code == Aztec::Keyboard::KEY_BACKSPACE) {
        key_code = "Backspace";
      }
      else if (code == Aztec::Keyboard::KEY_DELETE) {
        key_code = "Delete";
      }
      else if (code == Aztec::Keyboard::KEY_UP) {
        key_code = "Up";
      }
      else if (code == Aztec::Keyboard::KEY_DOWN) {
        key_code = "Down";
      }
      else if (code == Aztec::Keyboard::KEY_LEFT) {
        key_code = "Left";
      }
      else if (code == Aztec::Keyboard::KEY_RIGHT) {
        key_code = "Right";
      }
      else if (code == Aztec::Keyboard::KEY_RETURN) {
        key_code = "Return";
      }
      else if (code == Aztec::Keyboard::KEY_PAGEUP) {
        key_code = "PageUp";
      }
      else if (code == Aztec::Keyboard::KEY_PAGEDOWN) {
        key_code = "PageDown";
      }
      else if (code == Aztec::Keyboard::KEY_HOME) {
        key_code = "Home";
      }
      else if (code == Aztec::Keyboard::KEY_END) {
        key_code = "End";
      }
      else if (code == Aztec::Keyboard::KEY_ESCAPE) {
        key_code = "Escape";
      }
      else if (code == Aztec::Keyboard::KEY_TAB) {
        key_code = "Tab";
      }
    }

    return key_code;
  }

} // namespace Aztec