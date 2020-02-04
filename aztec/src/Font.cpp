#include <string>
#include <iostream>
#include <math.h>
#include "GameEngine.h"
#include "Font.h"

namespace Aztec {
  void Font::Init(char *filePath, int size)
  {
    _fontResource = NULL;

    _size = size;

    if (filePath == NULL || filePath[0] == '\0') {
      _filePath.assign("fonts/default.ttf");
    }
    else {
      _filePath.assign(filePath);
    }
    createFontResource();
  }

  Font::Font(char *filePath, int size) : _fontResource(nullptr)
  {
    Init(filePath, size);
  }

  Font::Font(char *filePath, int size, glm::vec4 color)
  {
    _color = color;
    Init(filePath, size);
  }

  Font::~Font()
  {
    unload();
  }

  int Font::getSize()
  {
    return _size;
  }


  float Font::getCharHeight()
  {
    return _fontResource->charHeight;
  }
  float Font::getCharWidth()
  {
    return _fontResource->charWidth;
  }

  const char *Font::getFilePath()
  {
    return _filePath.c_str();
  }


  void Font::createFontResource()
  {
    RESFont *newFontResource = ResourceManager::loadFont(_filePath.c_str(), _color, _size);
    if (_fontResource != NULL) {
      if (newFontResource != _fontResource) {
        ResourceManager::releaseFont(_fontResource);
      }
    }
    _fontResource = newFontResource;
  }

  RESFont *Font::getFontResource()
  {

    return _fontResource;
  }

  void Font::setColor(short r, short g, short b, short a)
  {
    _color.r = r;
    _color.g = g;
    _color.b = b;
    _color.b = a;
    createFontResource();
  }

  void Font::unload()
  {
    if (_fontResource) {
      ResourceManager::releaseFont(_fontResource);
    }
  }
} // namespace Aztec