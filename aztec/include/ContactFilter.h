#pragma once
#include <Box2d/Box2D.h>

namespace Aztec {
  /**
  * ContactFilter
  *
  * Represents different filter flags for each type of object and determines if
  * the collision has to occur between each of them.
  *
  * \author	Vicente Neto
  */
  class ContactFilter : public b2ContactFilter {
  public:
    /**
    * FilterFlags
    */
    static enum FilterFlags { NONE = 0, Camera = 2, Mouse = 4, Renderable = 8, Sensor = 16, Text = 32 };

    /**
    * Constuctor
    *
    */
    ContactFilter(void);

    /**
    * Destructor
    */
    ~ContactFilter(void);

    /**
    * Evaluates the filter values of both fixtures and decides if they should collide
    *
    * @return A boolean indicating if the fixtures should collide
    */
    bool ShouldCollide(b2Fixture *fixtureA, b2Fixture *fixtureB);
  };
} // namespace Aztec
