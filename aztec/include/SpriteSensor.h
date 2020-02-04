#pragma once
#include "Sprite.h"
namespace Aztec {

  /**
  * SpriteSensor
  *
  * Basically has the exact same functionalities as the Sprite class
  * The difference is that this automatically creates a rectangle sensor after the construction.
  *
  * \author	Vicente Neto
  */
  class SpriteSensor : public Sprite {
  public:
    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * @param filename
    * a string with the file path to the image.
    */
    SpriteSensor(char *filename);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * @param filename a string with the file path to the image.
    *
    * @param centerPivot Sets the pivot as the center of the image
    */
    SpriteSensor(char *filename, bool centerPivot);


    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * @param filename
    * a string with the file path to the image.
    * @param animFrameCount
    * keeps how many frames the sprite sheet has.
    * @param animFrameWidth
    * width of the frame in pixels.
    * @param animFrameHeight
    * height of the frame in pixels.
    */
    SpriteSensor(char *filename, int animFrameCount, float animFrameWidth, float animFrameHeight);


    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * @param filename
    * a string with the file path to the image.
    *
    * @param animFrameCount
    * keeps how many frames the sprite sheet has.
    *
    * @param animFrameWidth
    * width of the frame in pixels.
    *
    * @param animFrameHeight
    * height of the frame in pixels.
    *
    * @param centerPivot determines if the origin of the sprite will be set to the center automatically
    *
    */
    SpriteSensor(char *filename, int animFrameCount, float animFrameWidth, float animFrameHeight, bool centerPivot);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * @param filename
    * a string with the file path to the image.
    *
    *
    * @param animFrameWidth
    * width of the frame in pixels.
    *
    * @param animFrameHeight
    * height of the frame in pixels.
    *
    */
    SpriteSensor(char *filename, float animFrameWidth, float animFrameHeight);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * @param filename
    * a string with the file path to the image.
    *
    * @param animFrameWidth
    * width of the frame in pixels.
    *
    * @param animFrameHeight
    * height of the frame in pixels.
    *
    * @param centerPivot determines if the origin of the sprite will be set to the center automatically
    *
    */

    SpriteSensor(char *filename, float animFrameWidth, float animFrameHeight, bool centerPivot);
  };

}; // namespace Aztec