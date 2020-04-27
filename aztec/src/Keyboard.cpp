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

  bool Keyboard::isShiftPressed()
  {
    return keyIsDown(KEY_LSHIFT) || keyIsDown(KEY_RSHIFT);
  }

  bool Keyboard::isControlPressed()
  {
    return keyIsDown(KEY_LCTRL) || keyIsDown(KEY_RCTRL);
  }

  bool Keyboard::isAltPressed()
  {
    return keyIsDown(KEY_LALT) || keyIsDown(KEY_RALT);
  }

  Keyboard::Key Keyboard::readVKBuffer()
  {
    Key key;

    if (_keyBuffer.size() > 0) {
      key = _keyBuffer.back();
      _keyBuffer.pop_back();
    }
    return key;
  }

} // namespace Aztec
