#include "Keyboard.h"
#include <Windows.h>

#define UTF8 65001
#define LATIN 1252

namespace Aztec {

  wchar_t *Keyboard::codePageToUnicode(int codePage, const char *src)
  {
    if (!src) {
      return 0;
    }
    int srcLen = strlen(src);
    if (!srcLen) {
      wchar_t *w = new wchar_t[1];
      w[0]       = 0;
      return w;
    }

    int requiredSize = MultiByteToWideChar(codePage, 0, src, srcLen, 0, 0);

    if (!requiredSize) {
      return 0;
    }

    wchar_t *w = new wchar_t[requiredSize + 1];

    w[requiredSize] = 0;

    int retval = MultiByteToWideChar(codePage, 0, src, srcLen, w, requiredSize);

    if (!retval) {
      delete[] w;
      return 0;
    }

    return w;
  }

  char *Keyboard::unicodeToCodePage(int codePage, const wchar_t *src)
  {
    if (!src) {
      return 0;
    }
    int srcLen = wcslen(src);
    if (!srcLen) {
      char *x = new char[1];
      x[0]    = '\0';
      return x;
    }

    int requiredSize = WideCharToMultiByte(codePage, 0, src, srcLen, 0, 0, 0, 0);

    if (!requiredSize) {
      return 0;
    }

    char *x         = new char[requiredSize + 1];
    x[requiredSize] = 0;

    int retval = WideCharToMultiByte(codePage, 0, src, srcLen, x, requiredSize, 0, 0);
    if (!retval) {
      delete[] x;
      return 0;
    }

    return x;
  }

  Keyboard::Keyboard()
  {
    _bufferMaxSize = 8;
  }

  bool Keyboard::keyIsDown(int keyCode)
  {
    if (_keysPressed.find(keyCode) != _keysPressed.end()) {
      return true;
    }
    return false;
  }

  bool Keyboard::keyIsUp(int keyCode)
  {
    if (keyIsDown(keyCode)) {
      return false;
    }

    return true;
  }

  void Keyboard::keyPressed(int keyCode)
  {
    _keysPressed[keyCode] = keyCode;
  }

  void Keyboard::putOnKeyboardBuffer(Key k)
  {

    if (_keyBuffer.size() > _bufferMaxSize) {
      _keyBuffer.pop_back();
    }

    _keyBuffer.push_front(k);
  }

  void Keyboard::cleanBuffer()
  {
    _keyBuffer.clear();
  }

  void Keyboard::cleanPressed()
  {
    _keysPressed.clear();
  }

  void Keyboard::reset()
  {
    cleanBuffer();
    cleanPressed();
  }

  void Keyboard::keyReleased(int keyCode)
  {
    _keysPressed.erase(keyCode);
  }

  int Keyboard::bufferLength()
  {
    return _keyBuffer.size();
  }

  int Keyboard::readBuffer()
  {
    Key key;

    if (_keyBuffer.size() > 0) {
      key = _keyBuffer.back();
      _keyBuffer.pop_back();
    }

    return key.code;
  }

  int Keyboard::getModifiers(bool &extended)
  {
    int modifiers = 0;

    if (keyIsDown(KEY_LSHIFT)) { 
      modifiers |= KEY_LSHIFT; 
    }
    if (keyIsDown(KEY_LCTRL)) { 
      modifiers |= KEY_LCTRL;
    }
    if (keyIsDown(KEY_LALT)) {
      modifiers |= KEY_LALT; 
    }

    if (keyIsDown(KEY_RSHIFT)) {
      modifiers |= KEY_RSHIFT;
    }
    if (keyIsDown(KEY_RCTRL)) {
      modifiers |= KEY_RCTRL;
    }
    if (keyIsDown(KEY_RALT)) {
      modifiers |= KEY_RALT;
    }

    return modifiers;
  }

  Keyboard::Key Keyboard::readVKBuffer()
  {
    Key key;

    if (_keyBuffer.size() > 0) {
      key = _keyBuffer.back();
      _keyBuffer.pop_back();
#if 0
      if (!key.is_character) {
        switch (key.code) {
          case Keyboard::KEY_LEFT:
            key.code = VK_LEFT;
            break;
          case Keyboard::KEY_RIGHT:
            key.code = VK_RIGHT;
            break;
          case Keyboard::KEY_UP:
            key.code = VK_UP;
            break;
          case Keyboard::KEY_DOWN:
            key.code = VK_DOWN;
            break;
          case Keyboard::KEY_RETURN:
          case Keyboard::KEY_KP_ENTER:
            key.code = VK_RETURN;
            break;
          case Keyboard::KEY_ESCAPE:
            key.code = VK_ESCAPE;
            break;
          case Keyboard::KEY_DELETE:
            key.code = VK_DELETE;
            break;
          case Keyboard::KEY_TAB:
            key.code = VK_TAB;
            break;
          case Keyboard::KEY_HOME:
            key.code = VK_HOME;
            break;
          case Keyboard::KEY_END:
            key.code = VK_END;
            break;
          case Keyboard::KEY_PAGEUP:
            key.code = VK_PRIOR;
            break;
          case Keyboard::KEY_PAGEDOWN:
            key.code = VK_NEXT;
            break;
          case Keyboard::KEY_BACKSPACE:
            key.code = VK_BACK;
            break;
          default:
            break;
        }
      }
#endif
    }
    return key;
  }

} // namespace Aztec
