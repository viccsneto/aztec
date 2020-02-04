#pragma once

#include "Vector2.h"

namespace Aztec {
  /**
  * Transform
  *
  * Represents geometric properties such as position, rotation and scale
  *
  * \author	Vicente Neto
  *
  */
  class Transform {
  public:
    /**
    *
    * A static representation of a zero value Transform
    */
    static const Transform ZERO;
    /**
    * <DIV class="ah icona">Lua</DIV>
    * A Vector2 containg x and y coordinates
    */
    Vector2 position;

    /**
    * <DIV class="ah icona">Lua</DIV>
    * A Vector2 containg x and y scale factors (1.0 means normal size)
    */
    Vector2 scale;
    /**
    * <DIV class="ah icona">Lua</DIV>
    * A float representating the rotation value.
    */
    NumericProperty<float, void> rotation;

    /**
    * <DIV class="ah icona">Lua</DIV>
    * A float representating the ZOrder value.
    */
    NumericProperty<float, void> zorder;

    /**
    * <DIV class="ah icona">Lua</DIV>
    */
    Transform(void);

    /**
    * <DIV class="ah icona">Lua</DIV>
    */
    ~Transform(void);

    Transform &operator=(Transform &other)
    {
      if (&other != NULL) {
        position.assign(other.position);
        rotation = other.rotation;
        scale.assign(other.scale);
      }
      return *this;
    }
  };
} // namespace Aztec