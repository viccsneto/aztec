#include "Animation.h"
#include "GameEngine.h"


namespace Aztec {
  Animation::Animation(char *name, float width, float height)
  {
    _className.assign("Animation");

    _width           = width;
    _height          = height;
    _elapsedTime     = 0;
    int nameLength   = strlen(name);
    _idxCurrentFrame = -1;
    _name            = new char[nameLength + 1];
    strncpy(_name, name, nameLength);
    _name[nameLength] = '\0';
    Started           = false;
    Finished          = false;
    Loop              = true;
  }

  char *Animation::getName()
  {
    return _name;
  }

  double Animation::step()
  {
    if (_frames.size() == 1 && Loop)
      return 0;

    _elapsedTime += GameEngine::getInstance()->getElapsedTime();
    if (_elapsedTime >= _frames[_idxCurrentFrame]->getInterval()) {
      goNextFrame();
    }
    else if (_elapsedTime < 0) {
      goPreviousFrame();
    }

    return _elapsedTime;
  }

  const int Animation::getTotalFrames()
  {
    return _frames.size();
  }

  void Animation::deleteAllFrames()
  {
    _idxCurrentFrame = -1;
    for (vector<Frame *>::iterator i = _frames.begin(); i != _frames.end(); ++i) {
      delete (*i);
    }
  }

  void Animation::setFrameInterval(double interval)
  {
    for (vector<Frame *>::iterator i = _frames.begin(); i != _frames.end(); ++i) {
      (*i)->setInterval(interval);
    }
  }
  Animation::~Animation(void)
  {
    delete[] _name;
    deleteAllFrames();
  }
}; // namespace Aztec