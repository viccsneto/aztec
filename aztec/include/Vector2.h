#pragma once
#include "Property.h"
#include "LuaBinded.h"
namespace Aztec {
  /**
  * Vector2
  *
  * Represents a 2D vector
  *
  *
  * \author	Vicente Neto
  *
  */
  class Vector2 {
  public:
    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * A static representation of a zero value Vector2
    */
    static const Vector2 ZERO;

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * The x value of the Vector2
    */
    NumericProperty<float, void> x;

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * The y value of the Vector2
    */

    NumericProperty<float, void> y;

    /**
    * equals
    *
    * Check if this Vector2 is equal to another
    *
    * @param other The Vector2 being compared to this one.
    *
    * @return A boolean value (true if equals, false otherwise)
    */

    bool equals(Vector2 &other)
    {
      return (

          (x == other.x) && (y == other.y));
    }

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Copies the given Vector2 values to itself
    *
    * @param other The Vector2 from which the values will be copied
    *
    * @return A reference for itself
    */

    Vector2 *assign(Vector2 &other)
    {
      set(other.x, other.y);
      return this;
    }

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets the Vector2 values based on numeric parameters
    *
    * @param x The new x value of the Vector2
    *
    * @param y The new y value of the Vector2
    *
    */
    void set(float x, float y)
    {
      this->x.rawset(x);
      this->y.rawset(y);
      this->x = this->x;
      this->y = this->y;
    }

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Add the parameter values to the Vector2
    *
    * @param x The x value that will be added to the Vector2
    *
    * @param y The y value that will be added to the Vector2
    *
    */
    void add(float x, float y)
    {
      this->x.rawset(this->x.rawget() + x);
      this->y.rawset(this->y.rawget() + y);
      this->x = this->x;
      this->y = this->y;
    }

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Subtract the parameter values from the Vector2
    *
    * @param x The x value that will be subtracted from the Vector2
    *
    * @param y The y value that will be subtracted from the Vector2
    *
    */
    void sub(float x, float y)
    {
      add(-x, -y);
    }

    /**
    * <DIV class="ah icona">Lua</DIV>
    */
    Vector2();
    Vector2(float x, float y);

    /**
    * <DIV class="ah icona">Lua</DIV>
    */
    ~Vector2();

    Vector2 operator=(Vector2 &other)
    {
      assign(other);
      return Vector2(other);
    }

    Vector2 operator-()
    {
      return Vector2(-x, -y);
    }

    bool operator!=(Vector2 &other)
    {
      return !equals(other);
    }
  };
} // namespace Aztec