#pragma once
#include "GameObject.h"
#include "Plane.h"
#include "Texture.h"
#include "Shader.h"
#include "Sensor.h"
#include "Keyboard.h"
#include <luaelectron_browser.h>
#include <petunia/message.h>

#include <mutex>
#include <memory>

namespace Aztec {
   /**
  * WebBrowser
  *
  * A GameObject that implements Chromium Embedded Framework (The Open Source parts of Google Chrome Web Engine) and allows
  * to use practically all modern web technologies compatible with the Chrome Web browser (i.e: HTML5, CSS, Javascript, WebGL, etc)
  *
  * \author Vicente Neto
  *
  */
  class WebBrowser : public GameObject {
  public:
    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Creates a WebBrowser component
    *
    * @param url The url that will be opened at the browser startup
    * @param width The width of the browser component in pixels
    * @param height The height of the browser component in pixels
    * @param transparent A boolean indicating if the browser's background should be transparent (commonly desired when designing user interfaces such as HUD)
    */
    WebBrowser(const char *url, int width, int height, bool transparent);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Creates a WebBrowser component with white background
    *
    * @param url The url that will be opened at the browser startup
    * @param width The width of the browser component in pixels
    * @param height The height of the browser component in pixels
    */
    WebBrowser(const char *url, int width, int height);

    /**
    * Destructor
    */
    ~WebBrowser();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Navigates to an URL
    * @param url The destination URL that will be open
    */
    void Navigate(const char *url);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * GoBack in the browsing history
    */
    void GoBack();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * GoForward in the browsing history
    */
    void GoForward();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Stops the current loading state
    */
    void Stop();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Indicates if the browser is loading some document
    *
    */
    bool isLoading();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Refreshes the current document
    */
    void Refresh();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Executes Javascript in the main frame
    * @param script The javascript code that will be executed
    */
    void ExecuteScript(const char *script);

    /**
     * <DIV class="ah icona">Lua</DIV>
     *
     * Executes a script called from the webbrowser binded function window.ExecuteScript(source)
     *
     * @param script The source code that will be executed
     */
    void ExecuteCallBackScript(const char *script);


    /**
     * <DIV class="ah icona">Lua</DIV>
     *
     * Determines if the browser will retain the focus status and capture keyboard events even if the mouse is 
     * out of it
     *
     * @param always_focused a boolean indicating the status of the property
     */
    void setAlwaysFocused(bool always_focused);

    /**
     * <DIV class="ah icona">Lua</DIV>
     * getAlwaysFocused
     *
     * Checks if the browser is retaining the focus status and capturing keyboard events even if the mouse is
     * out of it
     *
     * @return a boolean indicating the status of the property
     */
    bool getAlwaysFocused();

    /**
    * Step
    *
    * Redirects user input(focus, mouse and keyboard) to the browser instance
    */
    void step();    

    /**
    * Draw
    *
    * Draws the offscreen rendering of the browser
    *
    */
    void draw();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets the shader program that will render this WebBrowser
    * @param shader The shader program that will render this WebBrowser
    */
    Shader *setShader(Shader *shader);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Gets the shader program that render this WebBrowser
    */
    Shader *getShader();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Gets the Plane of the WebBrowser which allows access to the texture objects
    * and raw drawing functions
    */
    Plane *getPlane();

  private:
    void UpdateTexture();
    void ExecuteReceivedScript();
    void Initialize(const char *url, int width, int height, bool transparent);
    void HandleMouseInputEvents();

    void Blur();

    void HandleMouseWheel();
    void HandleMouseMovement(int x, int y);
    void HandleMouseClicks(int x, int y);

    void Focus();

    bool hasFocus();
    std::string TranslateKeyCode(int code);
  private:
    Sensor * m_sensor;
    Plane *  m_plane;
    Texture *m_texture;
    ElectronBrowser *m_browser;
    int      m_width;
    int      m_height;
    std::mutex m_texture_mutex;
    std::mutex m_received_script_mutex;
    std::shared_ptr<Petunia::Message> m_texture_message;    
    std::shared_ptr<Petunia::Message> m_received_script_message;

    double m_last_click_time;
    bool   m_was_previously_focused;
    bool   m_always_focused;
    bool   m_has_focus;
    std::string PressedKeyToJSONInputEvent(Aztec::Keyboard::Key pressed_key);
  };
} // namespace Aztec
