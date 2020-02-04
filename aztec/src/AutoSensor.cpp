#include "AutoSensor.h"

namespace Aztec {
  AutoSensor::AutoSensor(float w, float h) : Sensor(w, h)
  {
  }


  AutoSensor::AutoSensor(float x, float y, float w, float h) : Sensor(x, y, w, h)
  {
  }

  AutoSensor::AutoSensor(float radius) : Sensor(radius)
  {
  }

  AutoSensor::AutoSensor(float x, float y, float radius) : Sensor(x, y, radius)
  {
  }

  GameObject *AutoSensor::getTarget()
  {
    return this;
  }

  AutoSensor::~AutoSensor(void)
  {
  }
} // namespace Aztec