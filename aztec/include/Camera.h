#pragma once

#include "GameObject.h"
#include <glm.hpp>

#include "Shader.h"

namespace Aztec {
  /**
  * Camera
  *
  * Represents a 2D camera that can show different scene positions
  *
  * \author	Vicente Neto
  */
  class Camera : public GameObject {
  protected:
    void      calculateTransforms();
    glm::vec4 _camera_balance;

  private:
    void      createFixtures();
    glm::mat4 _viewMatrix;
    glm::mat4 _projectionMatrix;

  public:
    glm::mat4 getDebugDrawProjectionMatrix();
    void      updateCameraUniforms(Shader *shader);
    void      setColorBalance(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    /**
    * <DIV class="ah icona">Lua</DIV>
    */
    Camera();

    /**
    * Destructor
    */
    ~Camera();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Puts the camera as the active camera for the engine
    */
    void activate();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * turns the camera off and makes the default camera the active one.
    */
    void deactivate();

    /**
    * getXOffSet
    *
    * gets the X offset of the camera. It's necessary to calculate things like mouse position and clip rectangles
    * @return a float representing the X offset of the camera
    */
    float getXOffSet();

    /**
    * getYOffSet
    *
    * gets the Y offset of the camera. It's necessary to calculate things like mouse position and clip rectangles
    * @return a float representing the Y offset of the camera
    */
    float getYOffSet();


    /**
    * step
    *
    * Aditional step instructions to assure that the rotation will be kept as 0
    */
    void step();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * move the camera to the center of the screen
    */
    void centerOnScreen();
  };
} // namespace Aztec
