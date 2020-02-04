#pragma once

namespace Aztec {
  /**
  * Rectangle
  *
  * Represents a very simple rectangle abstraction with cartesian coordinates, width and height.
  *
  * \author	Vicente Neto
  *
  */
  class Rectangle {
  public:
    /**
    * Contructor
    *
    * @param x The float x coordinate of the rectangle
    * @param y The float y coordinate of the rectangle
    * @param w The float width of the rectangle
    * @param h The float height of the rectangle
    */
    Rectangle();
    Rectangle(float x, float y, float w, float h);

    /**
    * x The float x coordinate of the rectangle
    */
    float x;

    /**
    * y The float y coordinate of the rectangle
    */
    float y;

    /**
    * w The float width of the rectangle
    */
    float w;

    /**
    * h The float height of the rectangle
    */
    float h;

    
    /**
    * bh The float bounds height of the rectangle
    */
    float bh;

  };
} // namespace Aztec