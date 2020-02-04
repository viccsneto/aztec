#pragma once

#include <GL/glew.h>
#include "ResourceManager.h"
#include "Animation.h"
#include "GameObject.h"
#include "Texture.h"
#include "Sensor.h"
#include <string>
#include <list>


#include "Plane.h"

namespace Aztec {
  using namespace std;
  /**
  * Sprite
  *
  * the Sprite class represents the main manipulated graphic objects in 2D games.
  * They generally contain all the frames of the animations, allowing the
  * existence of complex ones.
  *
  * \author	Vicente Neto
  */
  class Sprite : public GameObject {
  protected:
    void reScale();

  private:
    Plane *    _plane;
    Sensor *   _sensor;
    b2Fixture *_fixture;
    bool       _flipped;
    bool       _verticalFlipped;
    long       _elapsedTotal;

    bool     _isLoaded;
    Texture *_texture;
    char *   _imagePath;
    float    _animFrameWidth;
    float    _animFrameHeight;


    void              init(char *filename, int animFrameCount, float animFrameWidth, float animFrameHeight, double interval, bool pivotOnCenter);
    void              createFixtures();
    list<Animation *> _animations;
    Animation *       _currentAnimation;

  public:
    Sprite(RESTexture *texture);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * @param filename
    * a string with the file path to the image.
    */
    Sprite(char *filename);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * @param filename a string with the file path to the image.
    *
    * @param centerPivot Sets the pivot as the center of the image
    */
    Sprite(char *filename, bool centerPivot);

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
    Sprite(char *filename, int animFrameCount, float animFrameWidth, float animFrameHeight);


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
    Sprite(char *filename, int animFrameCount, float animFrameWidth, float animFrameHeight, bool centerPivot);

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
    Sprite(char *filename, float animFrameWidth, float animFrameHeight);

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

    Sprite(char *filename, float animFrameWidth, float animFrameHeight, bool centerPivot);


    /**
    * Destructor
    */
    ~Sprite();


    /**
    * load
    *
    * Loads the image to the memory.
    */
    virtual void load();

    /**
    * unload
    *
    * Removes the image from the memory.
    */
    virtual void unload();


    /**
    * Draw
    *
    * draws the frame on the game canvas using it's _globalTransform
    *
    */
    void draw();


    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Set the flip status of the sprite
    * Allow the image to be horizontally inverted preventing the need of design another version of the same image
    */
    void setFlipped(bool flipped);
    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Returns the horizontal flip status of the sprite
    */
    bool getFlipped();
    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Set the Vertical flip status of the sprite
    * Allow the image to be vertically inverted preventing the need of design an upsidedown version of the same image
    */
    void setVerticalFlipped(bool verticalFlipped);
    /**
    * <DIV class="ah icona">Lua</DIV>
    * Returns the vertical flip status of the sprite
    */
    bool getVerticalFlipped();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets the milliseconds interval of each animation frame
    */
    void setFrameInterval(long interval);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Gets the milliseconds interval of each animation frame
    */
    long getFrameInterval();

    /**
    * Step
    *
    * Step the Sprite
    */
    void step();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * calculates the center of the sprite and sets it as the pivot position
    */

    void pivotOnCenter();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Creates a animation with the specified name in the sprite
    *
    * @param name The name for the new animation
    *
    * @return a pointer to the new animation
    */
    Animation *newAnimation(char *name);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Removes the animation with the specified name from the sprite
    *
    * @param name The name of the animation that will be removed
    */
    void removeAnimation(char *name);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets the animation with the specified name as the current animation
    *
    * @param name The name of the animation that will be made current
    */
    Animation *setAnimation(char *name);
    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets the specified animation as the current animation
    *
    * @param animation a pointer to the animation that will be made current
    */

    Animation *setAnimation(Animation *animation);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Returns the current of animation of the sprite
    *
    * @return a pointer to the current animation
    */
    Animation *getCurrentAnimation();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Turns the sprite into a rectangular sprite sensor
    */
    void createSensor();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    *  Turns the sprite into a circular sprite sensor
    *
    * @param radius The radius of the sensor
    */
    void createCircleSensor(float radius);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Turns the sprite sensor a regular sprite
    */
    void destroySensor();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets the shader program that will render this Sprite
    @param shader The shader program that will rneder this Sprite
    */
    Shader *setShader(Shader *shader);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Gets the shader program that render this Sprite
    */
    Shader *getShader();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Gets the Plane of the sprite which allows access to the texture objects
    * and raw drawing functions
    */
    Plane *getPlane();
    /// Events
    virtual EventHandler OnAnimationStarted(Animation *animation);
    virtual EventHandler OnAnimationFinished(Animation *animation);
  };
} // namespace Aztec
