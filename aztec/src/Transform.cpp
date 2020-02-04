#include "Transform.h"

namespace Aztec {
  const Transform Transform::ZERO;

  Transform::Transform(void)
  {
    position.x = 0;
    position.y = 0;
    scale.x    = 1.0f;
    scale.y    = 1.0f;
    rotation   = 0.0f;
    zorder     = 0.0f;
  }


  Transform::~Transform(void)
  {
  }


} // namespace Aztec