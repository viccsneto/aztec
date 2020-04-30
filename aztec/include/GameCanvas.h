#pragma once
#include <stack>
#include "Camera.h"
#include <GLFW\glfw3.h>
#include "Rectangle.h"
#include <glm.hpp>
#include "Config.h"
#include "WebBrowser.h";
namespace Aztec {
  using namespace std;
  /**
  * GameCanvas
  *
  * Light Weight class designed to represent the rendering layer(Canvas) of Aztec
  *
  * \author	Vicente Neto
  *
  */

  class GameCanvas {
  public:
    void SetOffscreenRenderer(WebBrowser *browser);
    GLFWwindow *getWindow();

    /**
    * Constructor
    *
    * @param w
    * width of the screen in pixels
    *
    * @param h
    * height of the screen in pixels
    */
    GameCanvas(int w, int h);


    /**
    * beginRendering
    *
    * Starts the rendering process(clear buffer, sets camera position, etc)
    */
    void beginRendering();

    /**
    * endRendering
    *
    * Terminates the rendering process(swapBuffers, etc)
    */

    void endRendering();


    /**
    * Get Screen Width
    *
    * @return the width of the screen in pixels.
    */
    int getScreenWidth();

    /**
    * Get Screen Height
    *
    * @return the height of the screen in pixels.
    */
    int getScreenHeight();

    /**
    * pushClipRect
    *
    * @param rect A Retangulo pointer for the actual clipping bound
    */
    void pushClipRect(Rectangle *rect);

    /**
    * popClipRect
    *
    * @return A rect pointer for the last clipping bound
    */

    Rectangle *popClipRect();

    /**
    * Sets the color of the Canvas background
    * 
    * @param r The red component of the canvas color
    * @param g The greencomponent of the canvas color
    * @param b The blue component of the canvas color
    * @param a The alpha component of the canvas color
    */
    void setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    /**
    * Destructor
    *
    */
    ~GameCanvas();

    void activateContext();

  private:
    GLint       _lastSurface;
    GLFWwindow *_glfwWindow;
    void OffScreenRendering();
    WebBrowser *m_browser = nullptr;
    double m_offscreen_interval_sum;
    /**
    * Clear color
    */
    glm::vec4 _clearColor;

    /**
    * _stackClipRect
    *
    * The clipRect stack
    */
    stack<Rectangle *> _stackClipRect;

    /**
    * beginScissor
    * Marks the stencil buffer with the rectangle where drawing will be allowed.
    * It is a substitution for the glScissors function(that don't support rotation) and is responsible to provides a ClipRect functionality.
    * @param A Retangulo pointer to serve as drawing boundary
    */

    void beginScissor(Rectangle *rect, int level);
    /**
    * endScissor
    *
    * Removes the previous stencil buffer boundary.
    * @param The Retangulo pointer that will be removed from the stencil buffer.
    */
    void endScissor(Rectangle *rect, int level);
  };
} // namespace Aztec