#include "Text.h"
#include "Font.h"
#include "GameEngine.h"
#include <string>
#include <iostream>
#include <vector>
#include "Config.h"

#define TAB_SPACES 3
#define UNDERSCORE_Y_DISTANCE 2
#define UNDERSCORE_X_MARGIN 2
namespace Aztec {
  void Text::InitDefault()
  {
    _className.assign("Text");
    _lastcursorBlinkTime = 0;
    _cursorBlinkInterval = 500;
    _cursorBlinkNow      = false;
    _fixture             = NULL;
    _cursorPosition      = -1;
    //Clear the font pointer
    if (_font) {
      delete _font;
    }

    _font = NULL;

    setColor(255, 255, 255);

    //There is no text being pointed
    _text = NULL;
  }

  Text::Text() : GameObject(), _font(nullptr)
  {
    InitDefault();

    _fontPath = "";
    _fontSize = 22;

    _color.r       = 255;
    _color.g       = 255;
    _color.b       = 255;
    _font          = new Font((char *)_fontPath.c_str(), _fontSize, _color);
    Shader *shader = Shader::getDefaultShader();

    Texture *texture = new Texture(_font->getFontResource()->texture);

    for (int i = 0; i < 255; ++i) {
      _plane[i] = new Plane(shader, _font->getFontResource()->charPositions[i].bounds.width, _font->getFontResource()->charPositions[i].bounds.height, texture);
    }
  }

  Text::Text(int r, int g, int b, char *fontPath, int fontSize) : GameObject(), _font(nullptr), _text(nullptr)
  {
    _font = NULL;
    InitDefault();

    _fontPath = fontPath;
    _fontSize = fontSize;

    _color.r = r;
    _color.g = g;
    _color.b = b;
    _font    = new Font((char *)_fontPath.c_str(), _fontSize, _color);

    Shader *shader = Shader::getDefaultShader();
    Texture *texture = new Texture(_font->getFontResource()->texture);

    for (int i = 0; i < 255; ++i) {
      _plane[i] = new Plane(shader, _font->getFontResource()->charPositions[i].bounds.width, _font->getFontResource()->charPositions[i].bounds.height, texture);
    }
}

  Text::~Text()
  {
    unload();
  }

  void Text::setColor(int r, int g, int b)
  {
    _color.r = r;
    _color.g = g;
    _color.b = b;
    _color.a = 0;
    if (_font) {
      _font->setColor(r, g, b, 0);
    }
  }
  char *Text::getText()
  {
    return _text;
  }
  void Text::setText(char *text)
  {

    if (_text != NULL) {
      if (text != NULL) {
        if (strcmp(_text, text) == 0) {
          return;
        }
      }

      delete[] _text;
      _text = NULL;
    }

    if (text == NULL) {
      return;
    }

    int textLength = strlen(text);

    _text = new char[textLength + 1];


    strncpy(_text, text, textLength);
    _text[textLength] = '\0';
  }

  void Text::setDimension(float w, float h)
  {
    setClipRect(0, 0, w, h);
    createFixture();
  }

  void Text::createFixture()
  {

    if (_fixture) {
      _body->DestroyFixture(_fixture);
      _fixture = NULL;
    }

    if ((!_clipRect) || (_clipRect->w == 0 || _clipRect->h == 0)) {
      return;
    }

    b2Vec2 vertices[4];

    float x1, x2;
    float y1, y2;

    x1 = 0;
    y1 = 0;

    x2 = ((_clipRect->w) / Config::PHYSICS_PIXELS_METERS_RATIO);
    y2 = ((_clipRect->h) / Config::PHYSICS_PIXELS_METERS_RATIO);


    x1 -= ((_pivot.x * Transform.scale.x) / Config::PHYSICS_PIXELS_METERS_RATIO);
    y1 -= ((_pivot.y * Transform.scale.y) / Config::PHYSICS_PIXELS_METERS_RATIO);

    x2 -= ((_pivot.x * Transform.scale.x) / Config::PHYSICS_PIXELS_METERS_RATIO);
    y2 -= ((_pivot.y * Transform.scale.y) / Config::PHYSICS_PIXELS_METERS_RATIO);


    vertices[0].Set(x1, y1);
    vertices[1].Set(x2, y1);
    vertices[2].Set(x2, y2);
    vertices[3].Set(x1, y2);

    b2PolygonShape rect;
    rect.Set(vertices, 4);

    _fixture = _body->CreateFixture(&rect, 0);
    _fixture->SetSensor(true);

    b2Filter filter;

    //filter.categoryBits = ContactFilter::FilterFlags::Renderable|ContactFilter::FilterFlags::Text;
    filter.categoryBits = ContactFilter::FilterFlags::Renderable | ContactFilter::FilterFlags::Text;
    filter.maskBits     = ContactFilter::FilterFlags::Camera | ContactFilter::FilterFlags::Mouse;


    _fixture->SetFilterData(filter);
  }
  void Text::reScale()
  {
    GameObject::reScale();

    if (_clipRect) {
      createFixture();
    }
  }
  void Text::step()
  {
    GameObject::step();
    if ((GameEngine::getInstance()->getCurrentTime() - _lastcursorBlinkTime) > _cursorBlinkInterval) {
      _lastcursorBlinkTime = GameEngine::getInstance()->getCurrentTime();
      _cursorBlinkNow      = !_cursorBlinkNow;
    }
  }

  void Text::draw()
  {
    if (!Visible || !_font) {
      return;
    }

    RESFont *rfont = _font->getFontResource();

    GLfloat charHeight;

    int     i = 0;

    GLfloat x = 0;
    GLfloat y = 0;
    beginClipRect();

    if (_text != NULL) {
      if (_text != NULL) {
        for (i = 0; _text[i] != '\0'; i++) {
          if ((i == _cursorPosition) && (_cursorBlinkNow)) {
            drawCursor(x, y, rfont);
          }

          if (_text[i] == '\n') {
            x = 0;
            y = y + rfont->charHeight * Transform.scale.y;
            continue;
          }
          else if (_text[i] == '\t') {
            x += (rfont->charPositions[' '].advance * TAB_SPACES * Transform.scale.x);
            continue;
          }
          else if (_text[i] == ' ') {
            x += rfont->charPositions[' '].advance * Transform.scale.x;
            continue;
          }


          drawChar(x, y, _text[i], rfont);
          x = x + (rfont->charPositions[_text[i]].advance * Transform.scale.x);
        }
      }

      if ((i == _cursorPosition) && (_cursorBlinkNow)) {
        drawCursor(x, y, rfont);
      }
    }

    drawChildren();
    endClipRect();
  }

  void Text::drawChar(float x, float y, unsigned char c, RESFont *rfont)
  {
    y += rfont->charPositions[c].bounds.top * Transform.scale.y;

    _plane[c]->setColorBalance(_color.r, _color.g, _color.b, 1);
    _plane[c]->setScale(_globalTransform.scale.x, _globalTransform.scale.y, 1);
    _plane[c]->setTranslation(_globalTransform.position.x + x, _globalTransform.position.y + y, 0);

    _plane[c]->getShader()->SetUniform("texCoordX", rfont->charPositions[c].textureRect.left / rfont->texture->width);
    _plane[c]->getShader()->SetUniform("texCoordY", rfont->charPositions[c].textureRect.top / rfont->texture->height);
    _plane[c]->Draw();
  }

  void Text::load()
  {
  }

  void Text::selectByClick(float x, float y)
  {
    int   i;
    float tx = _globalTransform.position.x;
    float ty = _globalTransform.position.y;

    float charHeight = _font->getCharHeight() * _globalTransform.scale.y;

    RESFont *rfont = _font->getFontResource();

    if (x < tx) {
      setCursorPosition(1);
    }

    for (i = 0; _text[i] != '\0'; i++) {
      if ((x >= tx && x <= (tx + rfont->charPositions[_text[i]].advance * _globalTransform.scale.x)) && ((y >= ty) && (y <= ty + charHeight))

      ) {
        setCursorPosition(i);
        return;
      }

      if (_text[i] == '\n') {
        tx = _globalTransform.position.x;
        ty = ty + (charHeight * Transform.scale.y);
        continue;
      }
      tx += rfont->charPositions[_text[i]].advance * Transform.scale.x;
    }
    setCursorPosition(i);
  }

  void Text::unload()
  {
    delete _font;
    delete[] _text;
    for (int i = 0; i < 255; ++i) {
      delete _plane[i];
    }
  }

  float Text::getHeight()
  {
    float height = 0;
    int   i;

    if (_text != NULL) {
      for (i = 0; _text[i] != '\0'; i++) {
        if (_text[i] == '\n') {
          height++;
        }
      }
    }

    return height * _font->getCharHeight();
  }

  void Text::setCursorPosition(int i)
  {
    _cursorBlinkNow = true;
    _cursorPosition = i;
  }

  int Text::getCursorPosition()
  {
    return _cursorPosition;
  }

  void Text::drawCursor(float x, float y, RESFont *rfont)
  {
    drawChar(x, y + UNDERSCORE_Y_DISTANCE, '_', rfont);
    drawChar(x - UNDERSCORE_X_MARGIN, y + UNDERSCORE_Y_DISTANCE, '_', rfont);
    drawChar(x + UNDERSCORE_X_MARGIN, y + UNDERSCORE_Y_DISTANCE, '_', rfont);
  }

} // namespace Aztec
