#include <GL/glew.h>
#include "Camera.h"
#include "Config.h"
#include "GameCanvas.h"
#include "GameEngine.h"
#include <iostream>

namespace Aztec {
  void Camera::updateCameraUniforms(Shader *shader)
  {
    shader->SetUniformMatrix("viewMatrix", 4, 4, 1, glm::value_ptr(_viewMatrix));
    shader->SetUniform("camera_balance", _camera_balance.r, _camera_balance.g, _camera_balance.b, _camera_balance.a);
  }

  glm::mat4 Camera::getDebugDrawProjectionMatrix()
  {
    return _projectionMatrix;
  }

  void Camera::setColorBalance(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
  {
    _camera_balance = glm::vec4(r, g, b, a);
  }
  void Camera::createFixtures()
  {
    b2Vec2 vertices[4];

    float x1, x2;
    float y1, y2;

    x1 = 0;
    y1 = 0;

    x2 = (Config::SCREEN_WIDTH / Config::PHYSICS_PIXELS_METERS_RATIO);
    y2 = (Config::SCREEN_HEIGHT / Config::PHYSICS_PIXELS_METERS_RATIO);


    x1 -= (_pivot.x / Config::PHYSICS_PIXELS_METERS_RATIO);
    y1 -= (_pivot.y / Config::PHYSICS_PIXELS_METERS_RATIO);

    x2 -= (_pivot.x / Config::PHYSICS_PIXELS_METERS_RATIO);
    y2 -= (_pivot.y / Config::PHYSICS_PIXELS_METERS_RATIO);


    vertices[0].Set(x1, y1);
    vertices[1].Set(x2, y1);
    vertices[2].Set(x2, y2);
    vertices[3].Set(x1, y2);

    b2PolygonShape rect;
    rect.Set(vertices, 4);


    b2Fixture *fixture = _body->CreateFixture(&rect, 0);

    b2Filter filter;

    filter.categoryBits = ContactFilter::FilterFlags::Camera;
    filter.maskBits     = ContactFilter::FilterFlags::Renderable;

    fixture->SetFilterData(filter);
    fixture->SetSensor(true);
  }

  Camera::Camera() : GameObject()
  {
    _className.assign("Camera");
    _camera_balance = glm::vec4(1, 1, 1, 1);
    _pivot.x        = static_cast<float>(Config::SCREEN_WIDTH / 2);
    _pivot.y        = static_cast<float>(Config::SCREEN_HEIGHT / 2);
    createFixtures();
    centerOnScreen();
  }


  Camera::~Camera()
  {
  }


  void Camera::activate()
  {
    GameEngine::getInstance()->getContextGameState()->setActiveCamera(this);
    calculateTransforms();
  }

  void Camera::deactivate()
  {
    GameEngine::getInstance()->getContextGameState()->setActiveCamera(NULL);
  }

  float Camera::getXOffSet()
  {

    if (_parent == NULL) {
      return Transform.position.x - _pivot.x;
    }
    return _globalTransform.position.x - _pivot.x;
  }

  float Camera::getYOffSet()
  {
    if (_parent == NULL) {
      return Transform.position.y - _pivot.y;
    }
    return _globalTransform.position.y - _pivot.y;
  }


  void Camera::step()
  {
    GameObject::step();
    if (_globalTransform.rotation != 0) {
      Transform.rotation        = 0.0f;
      _globalTransform.rotation = 0.0f;
      _body->SetTransform(_body->GetPosition(), 0.0f);
    }
  }

  void Camera::calculateTransforms()
  {
    GameObject::calculateTransforms();

    _projectionMatrix = glm::ortho(0.0f, (float)(Config::SCREEN_WIDTH) / Config::PHYSICS_PIXELS_METERS_RATIO, (float)(Config::SCREEN_HEIGHT) / Config::PHYSICS_PIXELS_METERS_RATIO,
                                   0.0f, -0.1f, 1000.0f);
    _projectionMatrix =
        glm::translate(_projectionMatrix, glm::vec3(-getXOffSet() / Config::PHYSICS_PIXELS_METERS_RATIO, -getYOffSet() / Config::PHYSICS_PIXELS_METERS_RATIO, 0.0f));

    _viewMatrix = glm::lookAt(glm::vec3(0, 0, 1), //camera is at 0,0,1 in the world space
                              glm::vec3(0, 0, 0), //looks at the origin
                              glm::vec3(0, 1, 0)); //head is up. (0,-1,0) to look upside-down.

    _viewMatrix = glm::translate(_viewMatrix, glm::vec3(-getXOffSet(), -getYOffSet(), 0.0f));
  }
  void Camera::centerOnScreen()
  {
    Transform.position.set(static_cast<float>(Config::SCREEN_WIDTH / 2), static_cast<float>(Config::SCREEN_HEIGHT / 2));
  }
} // namespace Aztec