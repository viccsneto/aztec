#include <tolua.h>

#include "Frame.h"
#include "GameEngine.h"

namespace Aztec {
  const int Frame::DEFAULT_FRAME_INTERVAL = 33.0f;
  void      Frame::Init(float x, float y, double interval, bool flipped, float rotation)
  {
    this->x = x;
    this->y = y;
    this->setInterval(interval);
    this->flipped  = flipped;
    this->rotation = rotation;
  }

  void Frame::setInterval(double interval)
  {
    _interval = interval / 1000.0f;
  }

  double Frame::getInterval()
  {
    return _interval;
  }

  Frame::Frame(float x, float y, double interval)
  {
    _className.assign("Frame");
    Init(x, y, interval, false, 0.0f);
  }

  Frame::Frame(float x, float y, double interval, bool flipped)
  {
    _className.assign("Frame");
    Init(x, y, interval, flipped, 0.0f);
  }

  Frame::Frame(float x, float y, double interval, bool flipped, float rotation)
  {
    _className.assign("Frame");
    Init(x, y, interval, flipped, rotation);
  }

  Frame::~Frame(void)
  {
  }


}; // namespace Aztec