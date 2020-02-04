#pragma once
#include <vector>
#include <tolua.h>

#include "Frame.h"

namespace Aztec {
  using namespace std;
  /**
  * Animation
  *
  * Contains a collection of animation frames that will be played by the Sprite class objects
  *
  * \author Vicente Neto
  *
  */
  class Animation : public LuaBinded {
  private:
    vector<Frame *> _frames;
    float           _width;
    float           _height;
    int             _idxCurrentFrame;
    char *          _name;
    double          _elapsedTime;

  public:
    /**
      * <DIV class="ah icona">Lua</DIV>
      *  Determines if the animation will Loop after the last frame
      */
    bool Loop;

    /**
      * <DIV class="ah icona">Lua</DIV>
      * Will be flagged when the animation has been started
      */
    bool Started;

    /**
      * <DIV class="ah icona">Lua</DIV>
      * Will be flagged when the animation has been finished
      * Will be flagged when the animation has played the last frame and is not in Loop mode
      */
    bool Finished;

    /**
      * <DIV class="ah icona">Lua</DIV>
      *
      * Returns the animation name
      *
      * @return A pointer to the animation name
      */
    char *getName();

    /**
      *
      * Returns the number of frames in the animation
      *
      * @return a int representing the number of frames in the animation
      */

    const int getTotalFrames();

    /**
      * <DIV class="ah icona">Lua</DIV>
      * @param name a pointer to the animation name
      *
      * @param width the width of each frame of the animation
      *
      * @param height the height of each frame of the animation
      */
    Animation(char *name, float width, float height);

    /**
      * <DIV class="ah icona">Lua</DIV>
      *
      * Sets the current frame of the animation
      *
      * @param framenumber the number of the frame that will be made current
      *
      * @return a pointer to the current frame
      */
    Frame *setFrame(int framenumber)
    {
      if ((framenumber < 0) || (framenumber > static_cast<int>(_frames.size()) - 1)) {
        return NULL;
      }
      _elapsedTime     = 0;
      _idxCurrentFrame = framenumber;


      return _frames[_idxCurrentFrame];
    }

    /**
      * <DIV class="ah icona">Lua</DIV>
      *
      * Returns the current frame of the animation
      *
      * @return a pointer to the current frame
      */
    Frame *getCurrentFrame()
    {
      return _frames[_idxCurrentFrame];
    }

    /**
      *
      * Sets the current frame to the previous one
      *
      * @return a pointer to the current frame
      */
    Frame *goPreviousFrame()
    {
      unsigned int nextFrame = _idxCurrentFrame;

      if (--nextFrame < 0) {
        if (Loop) {
          return setFrame(_frames.size());
        }
        else {
          return _frames[_idxCurrentFrame];
        }
      }

      return setFrame(nextFrame);
    }

    /**
      *
      * Sets the current frame to the next one
      *
      * @return a pointer to the current frame
      */
    Frame *goNextFrame()
    {
      unsigned int nextFrame = _idxCurrentFrame + 1;

      if (Finished = (nextFrame >= _frames.size())) {
        if (Loop) {
          Finished = false;
          return setFrame(0);
        }
        else {
          return _frames[_idxCurrentFrame];
        }
      }

      return setFrame(nextFrame);
    }

    /**
      * <DIV class="ah icona">Lua</DIV>
      *
      * Puts a frame in the animation
      *
      * @param frame The Frame that will be inserted in The animation
      * @return a pointer to the frame
      */
    Frame *addFrame(Frame *frame)
    {
      if (_idxCurrentFrame == -1) {
        _idxCurrentFrame = 0;
      }
      _frames.push_back(frame);
      return frame;
    }

    /**
      * <DIV class="ah icona">Lua</DIV>
      *
      * Creates a new frame with the specified parameters
      *
      * @param x,y the texture coordinate of the frame
      *
      * @param interval the duration of the frame
      *
      * @return a pointer to the frame
      */
    Frame *addFrame(float x, float y, double interval)
    {
      return addFrame(new Frame(x, y, interval));
    }

    /**
      * <DIV class="ah icona">Lua</DIV>
      *
      * Creates a new frame with the specified parameters
      *
      * @param x,y the texture coordinate of the frame
      *
      * @param interval the duration of the frame
      *
      * @param flipped determines if the frame will be flipped when drawn
      *
      * @return a pointer to the frame
      */
    Frame *addFrame(float x, float y, double interval, bool flipped)
    {
      return addFrame(new Frame(x, y, interval, flipped));
    }

    /**
      * <DIV class="ah icona">Lua</DIV>
      *
      * Creates a new frame with the specified parameters
      *
      * @param x,y the texture coordinate of the frame
      *
      * @param interval the duration of the frame
      *
      * @param flipped determines if the frame will be flipped when drawn
      *
      * @param rotation determines if the sprite will rotate when drawn
      *
      * @return a pointer to the frame
      */
    Frame *addFrame(float x, float y, double interval, bool flipped, float rotation)
    {
      return addFrame(new Frame(x, y, interval, flipped, rotation));
    }

    /**
      *
      * Increments the elapsed time of the animation
      *
      * @return the total execution time of the current frame
      */
    double step();

    /**
      * <DIV class="ah icona">Lua</DIV>
      *
      * Creates a horizontal sequence of frames after the last frame of the animation
      *
      * @param x,y the texture coordinate of the first frame that will be created
      *
      * @param qtd the number of frames that will be created
      *
      * @param interval the duration of each frame
      */
    void addHorizontalSequence(float x, float y, int qtd, double interval)
    {
      if (qtd > 0) {
        for (int i = 0; i < qtd; i++) {
          addFrame(x + (i * _width), y, interval, false, 0);
        }
      }
      else {
        for (int i = qtd - 1; i >= 0; i--) {
          addFrame(x + (i * _width), y, interval, false, 0);
        }
      }
    }

    /**
      * <DIV class="ah icona">Lua</DIV>
      *
      * Creates a vertical sequence of frames after the last frame of the animation
      *
      * @param x,y the texture coordinate of the first frame that will be created
      *
      * @param qtd the number of frames that will be created
      *
      * @param interval the duration of each frame
      */
    void addVerticalSequence(float x, float y, int qtd, double interval)
    {
      if (qtd > 0) {
        for (int i = 0; i < qtd; i++) {
          addFrame(x, y + (i * _height), interval, false, 0);
        }
      }
      else {
        for (int i = qtd - 1; i >= 0; i--) {
          addFrame(x, y + (i * _height), interval, false, 0);
        }
      }
    }

    /**
      * <DIV class="ah icona">Lua</DIV>
      *
      * Clean the frames of the animation
      */
    void deleteAllFrames();

    /**
      * <DIV class="ah icona">Lua</DIV>
      *
      * Sets the interval of all frames in the animation
      *
      * @param interval the new duration for each frame
      */
    void setFrameInterval(double interval);


    /**
      * <DIV class="ah icona">Lua</DIV>
      */
    ~Animation(void);
  };
}; // namespace Aztec
