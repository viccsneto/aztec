#include "Vector2.h"
namespace Aztec {
  const Vector2 Vector2::ZERO;

  Vector2::Vector2(void)
  {
    x = 0.0f;
    y = 0.0f;
  }

  Vector2::Vector2(float x, float y)
  {
    this->x = x;
    this->y = y;
  }

  Vector2::~Vector2(void)
  {
  }
} // namespace Aztec