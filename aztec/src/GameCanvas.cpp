#include <GL/glew.h>
#include "GameCanvas.h"
#include "Plane.h"
#include "GameEngine.h"

#define OFFSCREEN_FRAME_RATE (1.0L / 30.0f)

namespace Aztec {
  void GameCanvas::beginScissor(Rectangle *rect, int level)
  {
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glStencilFunc(GL_EQUAL, level, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_INCR);

    Plane plane = Plane(Shader::getStencilShader(), rect->w, rect->h, NULL);
    plane.setTranslation(rect->x, rect->y, 0);
    plane.Draw();

    glStencilFunc(GL_EQUAL, level + 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
  }

  void GameCanvas::endScissor(Rectangle *rect, int level)
  {
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glStencilFunc(GL_EQUAL, level, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_DECR);

    Plane plane = Plane(Shader::getStencilShader(), rect->w, rect->h, NULL);
    plane.setTranslation(rect->x, rect->y, 0);
    plane.Draw();

    glStencilFunc(GL_EQUAL, level - 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
  }

  void GameCanvas::setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
  {
    _clearColor = glm::vec4(r, g, b, a);
  }

  void GameCanvas::OffScreenRendering()
  {
    m_offscreen_interval_sum += GameEngine::getInstance()->getElapsedTime();
    if (m_browser) {
      if (m_offscreen_interval_sum >= OFFSCREEN_FRAME_RATE) {
        size_t size = 3 * getScreenWidth() * getScreenHeight();
        static auto pixels = std::make_shared<std::string>();
        pixels->resize(size);
        
        glReadPixels(0, 0, getScreenWidth(), getScreenHeight(), GL_RGB, GL_UNSIGNED_BYTE, (void *)pixels->data());

        auto texture_message = std::make_shared<Petunia::Message>("update_canvas", pixels);
        m_browser->SendMessage(texture_message);
        m_offscreen_interval_sum = 0.0;
      }
    }
  }

  void GameCanvas::SetOffScreenRenderer(WebBrowser *browser)
  {
    m_browser = browser;
  }

  GLFWwindow *GameCanvas::getWindow()
  {
    return _glfwWindow;
  }

  GameCanvas::GameCanvas(int w, int h)
  {
    m_offscreen_interval_sum = 0.0f;
#ifdef _DEBUG
    setClearColor(0.5f, 0.5f, 0.5f, 1.0f);
#else
    setClearColor(0.0f, 0.0f, 0.0f, 1.0f);
#endif

    if (!glfwInit()) {
      GameEngine::getInstance()->registerError("GameCanvas: %s - <%s - [%d]>", "Couldn't initialize GLFW3...\n", __FILE__, __LINE__);
      return;
    }

    glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
    if (Config::FULLSCREEN) {
      _glfwWindow = glfwCreateWindow(w, h, Config::TITLE, glfwGetPrimaryMonitor(), NULL);
    }
    else {
      glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
      _glfwWindow = glfwCreateWindow(w, h, Config::TITLE, NULL, NULL);
    }

    if (!_glfwWindow) {
      GameEngine::getInstance()->registerError("GameCanvas: %s - <%s - [%d]>", "Couldn't create GLFW3 Window...\n", __FILE__, __LINE__);
      glfwTerminate();
      return;
    }

    activateContext();

    glEnable(GL_STENCIL_BUFFER);
    glEnable(GL_DOUBLEBUFFER);

    glewExperimental = GL_TRUE;
    glewInit();
  }

  void GameCanvas::endRendering()
  {
    glfwSwapBuffers(_glfwWindow);
    OffScreenRendering();
  }

  int GameCanvas::getScreenHeight()
  {
    return Config::SCREEN_HEIGHT;
  }

  int GameCanvas::getScreenWidth()
  {
    return Config::SCREEN_WIDTH;
  }

  void GameCanvas::beginRendering()
  {
    activateContext();

    glClearColor(_clearColor.r, _clearColor.g, _clearColor.b, _clearColor.a);

    glClearStencil(0);
    glClear(GL_STENCIL_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D); //We use basically TEXTURE_2D and QUADs to draw our images

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Enable support for transparency

    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST); // disable depth-testing (alpha)
    glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }

  GameCanvas::~GameCanvas()
  {
    glfwDestroyWindow(_glfwWindow);
    glfwTerminate();
  }

  void GameCanvas::pushClipRect(Rectangle *rect)
  {
    glEnable(GL_STENCIL_TEST);
    beginScissor(rect, _stackClipRect.size());
    _stackClipRect.push(rect);
  }

  Rectangle *GameCanvas::popClipRect()
  {
    Rectangle *rect;

    if (_stackClipRect.empty()) {
      return NULL;
    }

    rect = _stackClipRect.top();

    endScissor(rect, _stackClipRect.size());

    _stackClipRect.pop();

    if (_stackClipRect.empty()) {
      glDisable(GL_STENCIL_TEST);
      glClear(GL_STENCIL_BUFFER_BIT);
      glStencilFunc(GL_ALWAYS, 0, 0xFF);
      glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
    }

    return rect;
  }

  void GameCanvas::activateContext()
  {
    glfwMakeContextCurrent(_glfwWindow);
  }
} // namespace Aztec