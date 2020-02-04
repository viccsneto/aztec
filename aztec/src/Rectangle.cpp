#include "Rectangle.h"
#include "GameEngine.h"

namespace Aztec {
  Rectangle::Rectangle(float x, float y, float w, float h)
  {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
  }


  Rectangle::Rectangle()
  {
    this->x = 0;
    this->y = 0;
    this->w = 0;
    this->h = 0;
  }

} // namespace Aztec