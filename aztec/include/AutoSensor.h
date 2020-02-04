#pragma once
#include "Sensor.h"
namespace Aztec {
  /**
  * AutoSensor
  *
  * Basically has the exact same functionalities as the Sensor class
  * The difference is that this always return itself as the sensor target
  *
  * \author	Vicente Neto
  */
  class AutoSensor : public Sensor {
  public:
    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Makes a rectangle sensor
    *
    *
    *@param w the width of the rectangle sensor
    *
    *@param h the height of the rectangle sensor
    */
    AutoSensor(float w, float h);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Makes a rectangle sensor
    *
    *@param x the x coordinate of the sensor
    *
    *@param y the y coordinate of the sensor
    *
    *@param w the width of the rectangle sensor
    *
    *@param h the height of the rectangle sensor
    */
    AutoSensor(float x, float y, float w, float h);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Makes a circle sensor
    *
    *
    *@param radius the radius of the circle sensor
    *
    */
    AutoSensor(float radius);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Makes a circle sensor
    *
    *@param x the x coordinate of the sensor
    *
    *@param y the y coordinate of the sensor
    *
    *@param radius the radius of the circle sensor
    *
    */
    AutoSensor(float x, float y, float radius);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Returns itself
    *
    * @return A GameObject pointer to this AutoSensor
    */
    virtual GameObject *getTarget();

    /**
    * <DIV class="ah icona">Lua</DIV>
    */
    ~AutoSensor(void);
  };

} // namespace Aztec