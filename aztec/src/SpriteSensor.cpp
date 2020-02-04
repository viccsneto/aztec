#include "SpriteSensor.h"

namespace Aztec {
  SpriteSensor::SpriteSensor(char *filename) : Sprite(filename)
  {
    createSensor();
  }

  SpriteSensor::SpriteSensor(char *filename, bool centerPivot) : Sprite(filename, centerPivot)
  {
    createSensor();
  }

  SpriteSensor::SpriteSensor(char *filename, int animFrameCount, float animFrameWidth, float animFrameHeight) : Sprite(filename, animFrameCount, animFrameWidth, animFrameHeight)
  {
    createSensor();
  }

  SpriteSensor::SpriteSensor(char *filename, int animFrameCount, float animFrameWidth, float animFrameHeight, bool centerPivot)
      : Sprite(filename, animFrameCount, animFrameWidth, animFrameHeight, centerPivot)
  {

    createSensor();
  }

  SpriteSensor::SpriteSensor(char *filename, float animFrameWidth, float animFrameHeight) : Sprite(filename, animFrameWidth, animFrameHeight)
  {
    createSensor();
  }


  SpriteSensor::SpriteSensor(char *filename, float animFrameWidth, float animFrameHeight, bool centerPivot) : Sprite(filename, animFrameWidth, animFrameHeight, centerPivot)
  {

    createSensor();
  }


} // namespace Aztec