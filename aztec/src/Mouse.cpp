#include "Mouse.h"
#include "GameEngine.h"
#include "Camera.h"
#define MOUSE_SCROLL_SPEED 10.0f
namespace Aztec {
  bool Mouse::hasReleased = false;
  bool Mouse::hasClick    = false;
  bool Mouse::hasMovement = false;
  bool Mouse::hasWheel    = false;

  Mouse::Mouse()
  {
    _lastTime            = 0;
    _x                   = 0;
    _y                   = 0;
    _leftButtonPressed   = false;
    _rightButtonPressed  = false;
    _middleButtonPressed = false;

    _leftButtonJustPressed   = false;
    _rightButtonJustPressed  = false;
    _middleButtonJustPressed = false;

    _leftButtonJustReleased   = false;
    _rightButtonJustReleased  = false;
    _middleButtonJustReleased = false;
  }

  bool Mouse::isLeftButtonPressed()
  {
    return _leftButtonPressed;
  }

  bool Mouse::isRightButtonPressed()
  {
    return _rightButtonPressed;
  }

  bool Mouse::isMiddleButtonPressed()
  {
    return _middleButtonPressed;
  }

  bool Mouse::LeftButtonJustPressed()
  {
    return _leftButtonJustPressed;
  }

  bool Mouse::RightButtonJustPressed()
  {
    return _rightButtonJustPressed;
  }

  bool Mouse::MiddleButtonJustPressed()
  {
    return _middleButtonJustPressed;
  }

  bool Mouse::LeftButtonJustReleased()
  {
    return _leftButtonJustReleased;
  }

  bool Mouse::RightButtonJustReleased()
  {
    return _rightButtonJustReleased;
  }

  bool Mouse::MiddleButtonJustReleased()
  {
    return _middleButtonJustReleased;
  }

  int Mouse::getPosX()
  {
    Camera *camera = GameEngine::getInstance()->getCurrentGameState()->getActiveCamera();
    return _x + (int)camera->getXOffSet();
  }

  int Mouse::getPosY()
  {
    Camera *camera = GameEngine::getInstance()->getCurrentGameState()->getActiveCamera();
    return _y + (int)camera->getYOffSet();
  }

  double Mouse::getScrolledX()
  {
    return _scrolled_x;
  }

  double Mouse::getScrolledY()
  {
    return _scrolled_y;
  }
  void Mouse::moved(int x, int y)
  {
    _x          = x;
    _y          = y;
    hasMovement = true;
  }

  void Mouse::buttonPressed(int buttonCode)
  {
    switch (buttonCode) {
      case GLFW_MOUSE_BUTTON_LEFT:
        _leftButtonJustPressed = !_leftButtonPressed;
        _leftButtonPressed     = true;
        break;

      case GLFW_MOUSE_BUTTON_MIDDLE:

        _middleButtonJustPressed = !_middleButtonPressed;
        _middleButtonPressed     = true;
        break;

      case GLFW_MOUSE_BUTTON_RIGHT:
        _rightButtonJustPressed = !_rightButtonPressed;
        _rightButtonPressed     = true;
        break;
    }

    hasClick = true;
  }

  void Mouse::buttonReleased(int buttonCode)
  {
    switch (buttonCode) {
      case GLFW_MOUSE_BUTTON_LEFT:
        _leftButtonJustReleased = _leftButtonPressed;
        _leftButtonPressed      = false;
        break;

      case GLFW_MOUSE_BUTTON_MIDDLE:
        _middleButtonJustReleased = _middleButtonPressed;
        _middleButtonPressed      = false;
        break;

      case GLFW_MOUSE_BUTTON_RIGHT:
        _rightButtonJustReleased = _rightButtonPressed;
        _rightButtonPressed      = false;
        break;
    }
    hasReleased = true;
  }

  void Mouse::showCursor()
  {
    glfwSetInputMode(GameEngine::getInstance()->getGameCanvas()->getWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
  }

  void Mouse::Reset()
  {
    double currentTime = GameEngine::getInstance()->getCurrentTime();
    if (currentTime - _lastTime >= 0.05L) {
      Mouse::hasClick          = false;
      Mouse::hasMovement       = false;
      Mouse::hasReleased       = false;
      Mouse::hasWheel          = false;
      _scrolled_x              = 0;
      _scrolled_y              = 0;
      _leftButtonJustPressed   = false;
      _rightButtonJustPressed  = false;
      _middleButtonJustPressed = false;

      _leftButtonJustReleased   = false;
      _rightButtonJustReleased  = false;
      _middleButtonJustReleased = false;
      _lastTime                 = currentTime;
    }
  }

  void Mouse::hideCursor()
  {
    glfwSetInputMode(GameEngine::getInstance()->getGameCanvas()->getWindow(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
  }

  void Mouse::scrolled(double x, double y)
  {
    Mouse::hasWheel = true;
    _scrolled_x     = x * MOUSE_SCROLL_SPEED;
    _scrolled_y     = y * MOUSE_SCROLL_SPEED;
  }

} // namespace Aztec