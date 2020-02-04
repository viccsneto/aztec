#pragma once
#include "ContactFilter.h"
#include "GameObject.h"
#include "PointList2D.h"
#include <Box2D/Box2D.h>
namespace Aztec {
  /**
  * Sensor
  *
  * Responsible to detect physics contacts and notifies its owners of the event
  *
  * \author	Vicente Neto
  *
  */
  class Sensor : public GameObject {
  protected:
    float       _width;
    float       _height;
    float       _radius;
    PointList2D _pointlist;
    b2Fixture * _fixture;

    void init(float x, float y);

  public:
    void setFilterData();
    void setFilterData(int category_bits, int mask_bits);
    /**
    * Constructor
    *
    * Don't initialize yet
    */
    Sensor(void);
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
    Sensor(float w, float h);

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
    Sensor(float x, float y, float w, float h);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Makes a circle sensor
    *
    *
    *@param radius the radius of the circle sensor
    *
    */
    Sensor(float radius);

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
    Sensor(float x, float y, float radius);


    /**
     * <DIV class="ah icona">Lua</DIV>
    *
    * Makes a polygon sensor
    *
    * @param point_list a PointList2D containing the points of the polygon
    *
    */
    Sensor(PointList2D point_list);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Returns the target of the collision
    */
    virtual GameObject *getTarget();

    /**
    * createFixture
    *
    * creates a circle fixture
    *
    * @param radius The radius of the circle
    *
    */
    void createFixture(float radius);

    /**
    * createFixture
    *
    * creates a rectangle fixture
    *
    * @param w The width of the rectangle
    *
    * @param h The height of the rectangle
    */
    void createFixture(float w, float h);

    /**
    * createFixture
    *
    * creates a polygon fixture
    *
    * @param point_list a PointList2D containing the points of the polygon
    *    
    */
    void createFixture(PointList2D point_list);

    /**
    * reScale
    */

    void reScale();

    /**
    * <DIV class="ah icona">Lua</DIV>
    */
    ~Sensor(void);
  };

} // namespace Aztec