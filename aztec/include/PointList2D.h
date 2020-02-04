#pragma once
#include "LuaBinded.h"
#include "Vector2.h"
#include <vector>

namespace Aztec {
  using namespace std;
  /**
  * Represents a list of Vector2D
  *
  * It is very useful and more intuitive to define polygons adding point by point instead
  * of passing an array of values
  * It turn the process of passing such kind of list from the Lua Context to C++ into a
  * more concrete operation
  */

  class PointList2D : public LuaBinded {
  public:
    /**
    * Clear the list of points
    */
    void clear();

    /**
    * Adds a point to the list
    *
    * @param x The x value of the point
    * @param y The y value of the point
    *
    * @return The point added to the list
    */
    Vector2 add(float x, float y);

    /**
    * Adds a point to the list
    *
    * @param v A Vector2 representing the point that will be added to the list    
    *
    * @return The point added to the list
    */
    Vector2 add(Vector2 v);

    /**
    * Gets the point at the given index from the list
    *
    * @param idx The index of the the point on the list

    * @return The point at the given index or Vector2(-INFINITY,-INFINITY) if the index is out of range
    */
    Vector2 get(int idx);

    /**
    * Updates the values of the point at the given index
    *
    * @param idx The index of the the point on the list
    * @param x The x value of the point
    * @param y The y value of the point
    *
    * @return The updated point at the given index or Vector2(-INFINITY,-INFINITY) if the index is out of range
    */
    Vector2 set(int idx, float x, float y);

    /**
    * Updates the values of the point at the given index
    *
    * @param idx The index of the the point on the list
    * @param v A Vector2 representing the point that will be added to the list    
    *
    * @return The updated point at the given index or Vector2(-INFINITY,-INFINITY) if the index is out of range
    */
    Vector2 set(int idx, Vector2 v);

    /**
    * Removes the point at the given index
    *
    * @param idx The index of the the point on the list
    *
    * @return The removed point or Vector2(-INFINITY,-INFINITY) if the index is out of range
    */
    Vector2 remove(int idx);

    /*
    * Returns the list of points represented by this object
    */
    vector<Vector2> getList();
    PointList2D();
    ~PointList2D();

  private:
    vector<Vector2> m_point_list;
  };

} // namespace Aztec