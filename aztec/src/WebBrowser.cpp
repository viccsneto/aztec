#include "WebBrowser.h"
#include "GameEngine.h"
#include "ResourceManager.h"
#include "Shader.h"

#define CEF_DOUBLE_CLICK_INTERVAL 0.250f
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

    bool extended = false;
    int modifiers = GameEngine::getInstance()->getKeyboard()->getModifiers(extended);
    int x = GameEngine::getInstance()->getMouse()->getPosX() - getGlobalTransform().position.x;
    int y = GameEngine::getInstance()->getMouse()->getPosY() - getGlobalTransform().position.y;

    static bool has_focus = false;

    if (mouseOver) {
      if (GameEngine::getInstance()->getMouse()->LeftButtonJustPressed()) {

        if (!m_was_previously_focused) {
          GameEngine::getInstance()->getKeyboard()->cleanBuffer();
          m_browser->Execute("mainWindow.focusOnWebView();");
          has_focus = true;
        }

        int count = 1;
        double click_interval = (GameEngine::getInstance()->getCurrentTime() - m_last_click_time);
        if (click_interval < CEF_DOUBLE_CLICK_INTERVAL) {
          count++;
        }

        std::string script = "mainWindow.webContents.sendInputEvent({\"type\":\"mouseDown\", \"button\": \"left\", \"x\":" + std::to_string(x) + ",\"y\":" + std::to_string(y) +
                             ",\"clickCount\":" + std::to_string(count) + "})";
        m_browser->Execute(script.c_str());        
      }

      if (GameEngine::getInstance()->getMouse()->LeftButtonJustReleased()) {
        std::string script =
            "mainWindow.webContents.sendInputEvent({\"type\":\"mouseUp\", \"button\": \"left\", \"x\": " + std::to_string(x) + ",\"y\": " + std::to_string(y) + "})";
        m_browser->Execute(script.c_str());
        m_last_click_time = GameEngine::getInstance()->getCurrentTime();
      }

      if (GameEngine::getInstance()->getMouse()->hasMovement) {
        std::string script = "mainWindow.webContents.sendInputEvent({\"type\":\"mouseMove\", \"x\": " + std::to_string(x) + ",\"y\": " + std::to_string(y) + " })";
        m_browser->Execute(script.c_str());
      }

      if (GameEngine::getInstance()->getMouse()->RightButtonJustPressed()) {
        std::string script = "mainWindow.webContents.sendInputEvent({\"type\":\"mouseDown\", \"button\": \"right\", \"x\":" + std::to_string(x) + ",\"y\":" + std::to_string(y) +
          ",\"clickCount\":1})";
        m_browser->Execute(script.c_str());
      }
      
      else if (GameEngine::getInstance()->getMouse()->RightButtonJustReleased()) {
        std::string script = "mainWindow.webContents.sendInputEvent({\"type\":\"mouseUp\", \"button\": \"right\", \"x\":" + std::to_string(x) + ",\"y\":" + std::to_string(y) +
          ",\"clickCount\":1})";
        m_browser->Execute(script.c_str());
      }

      if (GameEngine::getInstance()->getMouse()->MiddleButtonJustPressed()) {
        std::string script = "mainWindow.webContents.sendInputEvent({\"type\":\"mouseDown\", \"button\": \"middle\", \"x\":" + std::to_string(x) + ",\"y\":" + std::to_string(y) +
          ",\"clickCount\":1})";
        m_browser->Execute(script.c_str());
      }

      else if (GameEngine::getInstance()->getMouse()->MiddleButtonJustReleased()) {
        std::string script = "mainWindow.webContents.sendInputEvent({\"type\":\"mouseUp\", \"button\": \"middle\", \"x\":" + std::to_string(x) + ",\"y\":" + std::to_string(y) +
          ",\"clickCount\":1})";
        m_browser->Execute(script.c_str());
      }
      
      if (GameEngine::getInstance()->getMouse()->hasWheel) {
        std::string script = "mainWindow.webContents.sendInputEvent("
          "{\"type\":\"mouseWheel\","
          "\"x\":0,"
          "\"y\":0,"
          "\"deltaX\":" + std::to_string((int)GameEngine::getInstance()->getMouse()->getScrolledX()) + ","
          "\"deltaY\":" + std::to_string((int)GameEngine::getInstance()->getMouse()->getScrolledY()) +
          "})";
        
        m_browser->Execute(script.c_str());
      }
   
    } else {
      if (has_focus) {
        if (!m_always_focused) {
          m_browser->Execute("mainWindow.blur();");
          m_was_previously_focused = false;
          has_focus = false;
        }
      }

    }
    /*
        if (has_focus || m_always_focused) {

          if (!m_was_previously_focused) {
              m_browser->GetHost()->SendFocusEvent(true);
            m_was_previously_focused = true;
          }

          while (GameEngine::getInstance()->getKeyboard()->bufferLength() > 0) {
            CefKeyEvent event;

            Keyboard::Key key = GameEngine::getInstance()->getKeyboard()->readVKBuffer();

            event.windows_key_code = key.code;
            event.native_key_code = key.code;
            event.unmodified_character = key.code;
            event.modifiers = modifiers;

            if (key.release_event)
                event.type = KEYEVENT_KEYUP;
            else {
              if (key.is_character) {
                event.character = key.code;
                event.type = KEYEVENT_CHAR;
              } else
                event.type = KEYEVENT_RAWKEYDOWN;
            }
            m_browser->GetHost()->SendKeyEvent(event);
          }
        }
      */
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

} // namespace Aztec