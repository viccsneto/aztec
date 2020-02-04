#pragma once
#include "LuaBinded.h"

namespace Aztec {
  /**
  * Frame
  *
  * Represents a frame in a Sprite animation
  *
  * \author	Vicente Neto
  *
  */
  class Frame : public LuaBinded {
  private:
    void Init(float x, float y, double interval, bool flipped, float rotation);
    /**
    * _interval
    *
    * the duration of the frame
    */
    double _interval;

  public:
    void             setInterval(double interval);
    double           getInterval();
    static const int DEFAULT_FRAME_INTERVAL;

    /**
    * flipped
    *
    * determines if the frame will be flipped when drawn
    */
    bool flipped;

    /**
    * rotation
    *
    * determines if the frame will be rotated when drawn
    */
    float rotation;


    /**
    * x
    * the x coordinate of the frame in the sprite texture
    */
    float x;

    /**
    * y
    * the y coordinate of the frame in the sprite texture
    */
    float y;

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    *
    * @param x,y the texture coordinate of the frame
    *
    * @param interval the duration of the frame
    *
    */
    Frame(float x, float y, double interval);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    *
    * @param x,y the texture coordinate of the frame
    *
    * @param interval the duration of the frame
    *
    * @param flipped determines if the frame will be flipped when drawn
    *
    */
    Frame(float x, float y, double interval, bool flipped);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    *
    * @param x,y the texture coordinate of the frame
    *
    * @param interval the duration of the frame
    *
    * @param flipped determines if the frame will be flipped when drawn
    *
    * @param rotation determines if the sprite will rotate when drawn
    */
    Frame(float x, float y, double interval, bool flipped, float rotation);

    /**
    * Destructor
    */
    ~Frame(void);
  };
}; // namespace Aztec
