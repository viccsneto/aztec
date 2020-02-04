#include "Sprite.h"
#include "GameCanvas.h"
#include "GameEngine.h"
#include <iostream>
#include "Config.h"
#include "EventDispatcher.h"

namespace Aztec {


  Sprite::Sprite(RESTexture *texture) : GameObject()
  {
    _isLoaded = true;
    _texture  = new Texture(texture);
    init("", 1, _texture->getWidth(), _texture->getHeight(), Frame::DEFAULT_FRAME_INTERVAL, false);
  }
  Sprite::Sprite(char *filename) : GameObject()
  {
    init(filename, 1, 0, 0, Frame::DEFAULT_FRAME_INTERVAL, false);
  }

  Sprite::Sprite(char *filename, bool centerPivot) : GameObject()
  {
    init(filename, 1, 0, 0, Frame::DEFAULT_FRAME_INTERVAL, centerPivot);
  }


  Sprite::Sprite(char *filename, float animFrameWidth, float animFrameHeight) : GameObject()
  {
    init(filename, 0, animFrameWidth, animFrameHeight, Frame::DEFAULT_FRAME_INTERVAL, false);
  }

  Sprite::Sprite(char *filename, float animFrameWidth, float animFrameHeight, bool centerPivot) : GameObject()
  {
    init(filename, 0, animFrameWidth, animFrameHeight, Frame::DEFAULT_FRAME_INTERVAL, centerPivot);
  }

  Sprite::Sprite(char *filename, int animFrameCount, float animFrameWidth, float animFrameHeight) : GameObject()
  {
    init(filename, animFrameCount, animFrameWidth, animFrameHeight, Frame::DEFAULT_FRAME_INTERVAL, false);
  }

  Sprite::Sprite(char *filename, int animFrameCount, float animFrameWidth, float animFrameHeight, bool centerPivot) : GameObject()
  {
    init(filename, animFrameCount, animFrameWidth, animFrameHeight, Frame::DEFAULT_FRAME_INTERVAL, centerPivot);
  }


  void Sprite::createFixtures()
  {
    return;

    if (_fixture != NULL) {
      _body->DestroyFixture(_fixture);
      _fixture = NULL;
    }

    b2Vec2 vertices[4];

    float x1, x2;
    float y1, y2;

    x1 = 0;
    y1 = 0;

    x2 = ((_animFrameWidth * Transform.scale.x) / Config::PHYSICS_PIXELS_METERS_RATIO);
    y2 = ((_animFrameHeight * Transform.scale.y) / Config::PHYSICS_PIXELS_METERS_RATIO);


    x1 -= ((_pivot.x * Transform.scale.x) / Config::PHYSICS_PIXELS_METERS_RATIO);
    y1 -= ((_pivot.y * Transform.scale.y) / Config::PHYSICS_PIXELS_METERS_RATIO);

    x2 -= ((_pivot.x * Transform.scale.x) / Config::PHYSICS_PIXELS_METERS_RATIO);
    y2 -= ((_pivot.y * Transform.scale.y) / Config::PHYSICS_PIXELS_METERS_RATIO);


    vertices[0].Set(x1, y1);
    vertices[1].Set(x2, y1);
    vertices[2].Set(x2, y2);
    vertices[3].Set(x1, y2);

    b2PolygonShape rect;
    rect.Set(vertices, 4);

    _fixture = _body->CreateFixture(&rect, 0);


    _fixture->SetSensor(true);

    b2Filter filter;

    filter.categoryBits = ContactFilter::FilterFlags::Renderable;
    filter.maskBits     = ContactFilter::FilterFlags::Camera;
    _fixture->SetFilterData(filter);
  }

  void Sprite::reScale()
  {
    GameObject::reScale();
    createFixtures();
  }


  Sprite::~Sprite()
  {
    unload();
  }

  void Sprite::init(char *filename, int animFrameCount, float animFrameWidth, float animFrameHeight, double interval, bool centerPivot)
  {
    _className.assign("Sprite");
    _sensor = NULL;

    _fixture          = NULL;
    _currentAnimation = NULL;


    int filenameLength;
    filenameLength = strlen(filename);
    _imagePath     = new char[filenameLength + 1];
    strncpy(_imagePath, filename, filenameLength);
    _imagePath[filenameLength] = '\0';

    _isLoaded        = false;
    _flipped         = false;
    _verticalFlipped = false;
    _elapsedTotal    = 0;

    load();

    if (animFrameWidth == 0) {
      animFrameWidth = _texture->getOriginalWidth();
    }

    if (animFrameHeight == 0) {
      animFrameHeight = _texture->getOriginalHeight();
    }

    _animFrameHeight = animFrameHeight;
    _animFrameWidth  = animFrameWidth;


    if (animFrameCount > 0) {
      Animation *anim = newAnimation("default");
      anim->addHorizontalSequence(0, 0, animFrameCount, interval);
    }

    if (centerPivot) {
      pivotOnCenter();
    }


    Shader *shader = Shader::createFromFiles(NULL, NULL);

    _plane = new Plane(shader, _animFrameWidth, _animFrameHeight, _texture);

    createFixtures();
  }

  void Sprite::draw()
  {
    if (!Visible || !_currentAnimation) {
      return;
    }


    beginClipRect();

    //if (insideCameraBounds)
    {
      int   xPivotInverter = 1;
      int   yPivotInverter = 1;
      float xRotation      = 0;
      float yRotation      = 0;

      if ((_flipped && !_currentAnimation->getCurrentFrame()->flipped) || (!_flipped && _currentAnimation->getCurrentFrame()->flipped)) {
        yRotation      = 180;
        xPivotInverter = -1;
      }
      //MULTIPLY BY -1
      if (_verticalFlipped) {
        xRotation      = 180;
        yPivotInverter = -1;
      }

      _plane->setPivot(_pivot.x.rawget() * _globalTransform.scale.x * xPivotInverter, _pivot.y.rawget() * _globalTransform.scale.y * yPivotInverter, 0);

      _plane->setTranslation(_globalTransform.position.x, _globalTransform.position.y, 0);
      _plane->setScale(_globalTransform.scale.x, _globalTransform.scale.y, 1.0f);
      _plane->setPostRotation(xRotation, yRotation, 0);
      _plane->setRotation(0, 0, -_globalTransform.rotation);

      _plane->getShader()->SetUniform("texCoordX", _currentAnimation->getCurrentFrame()->x / _texture->getWidth());
      _plane->getShader()->SetUniform("texCoordY", _currentAnimation->getCurrentFrame()->y / _texture->getHeight());
      _plane->getShader()->SetUniform("time", GameEngine::getInstance()->getCurrentTime());
      _plane->Draw();
    }
    drawChildren();
    endClipRect();
  }


  bool Sprite::getFlipped()
  {
    return _flipped;
  }

  bool Sprite::getVerticalFlipped()
  {
    return _verticalFlipped;
  }

  void Sprite::setFlipped(bool flipped)
  {
    _flipped = flipped;
  }

  void Sprite::setVerticalFlipped(bool verticalFlipped)
  {
    _verticalFlipped = verticalFlipped;
  }


  void Sprite::load()
  {
    if (!_isLoaded) {

      if (strlen(_imagePath) > 0) {

        _texture = new Texture(ResourceManager::loadImage(_imagePath));

        if (!_texture) {
          GameEngine::getInstance()->registerError("Image %s could not be loaded. %s [%d]", _imagePath, __FILE__, __LINE__);
          exit(1);
        }
      }
    }
    _isLoaded = true;
  }

  void Sprite::unload()
  {


    for (list<Animation *>::iterator i = _animations.begin(); i != _animations.end(); ++i) {
      delete (*i);
    }

    delete _plane;

    if (_isLoaded) {
      if (_imagePath != NULL) {
        ResourceManager::releaseImage(_imagePath);

        delete[] _imagePath;
        _imagePath = NULL;
      }
      _isLoaded = false;
    }
  }

  void Sprite::setFrameInterval(long interval)
  {
    _currentAnimation->setFrameInterval(interval);
  }

  long Sprite::getFrameInterval()
  {
    if (_currentAnimation != NULL) {
      return _currentAnimation->getCurrentFrame()->getInterval();
    }
    return 0;
  }


  void Sprite::step()
  {
    if (!Enabled) {
      return;
    }

    GameObject::step();


    if (_currentAnimation) {
      if (!_currentAnimation->Started) {
        _currentAnimation->Started = true;
        EventDispatcher::doOnAnimationStarted(this, _currentAnimation);
      }

      _currentAnimation->step();


      if (_currentAnimation->Finished) {
        EventDispatcher::doOnAnimationFinished(this, _currentAnimation);
      }

      _globalTransform.rotation += _currentAnimation->getCurrentFrame()->rotation;
    }
  }


  void Sprite::pivotOnCenter()
  {
    _pivot.x = _animFrameWidth / 2;
    _pivot.y = _animFrameHeight / 2;
    createFixtures();
  }

  Animation *Sprite::newAnimation(char *name)
  {

    Animation *animation = new Animation(name, _animFrameWidth, _animFrameHeight);
    _animations.push_back(animation);
    if (_currentAnimation == NULL) {
      _currentAnimation = animation;
    }
    return animation;
  }

  void Sprite::removeAnimation(char *name)
  {
    for (list<Animation *>::iterator i = _animations.begin(); i != _animations.end(); ++i) {
      if ((*i) != _currentAnimation) {
        delete (*i);
        return;
      }
    }
  }

  Animation *Sprite::setAnimation(char *name)
  {
    for (list<Animation *>::iterator i = _animations.begin(); i != _animations.end(); ++i) {
      if (strcmp((*i)->getName(), name) == 0) {
        return setAnimation((*i));
      }
    }

    return NULL;
  }

  Animation *Sprite::setAnimation(Animation *animation)
  {
    for (list<Animation *>::iterator i = _animations.begin(); i != _animations.end(); ++i) {
      if ((*i) == animation) {
        _currentAnimation           = (*i);
        _currentAnimation->Started  = false;
        _currentAnimation->Finished = false;
        _currentAnimation->setFrame(0);

        return (*i);
      }
    }

    return NULL;
  }


  void Sprite::createSensor()
  {
    _className.assign("SpriteSensor");
    if (_sensor) {
      _children.remove(_sensor);
      delete _sensor;
    }

    _sensor = new Sensor();
    _sensor->setPivot(_pivot.x, _pivot.y);
    _sensor->createFixture(_animFrameWidth, _animFrameHeight);
    _sensor->Transform.scale.assign(Transform.scale);


    addGameObject(_sensor);
  }

  void Sprite::createCircleSensor(float radius)
  {
    if (_sensor) {
      _children.remove(_sensor);
      delete _sensor;
    }
    _sensor = new Sensor(((_animFrameWidth / 2 - _pivot.x) * Transform.scale.x), ((_animFrameHeight / 2 - _pivot.y) * Transform.scale.y), radius);
    addGameObject(_sensor);
  }

  Animation *Sprite::getCurrentAnimation()
  {
    return _currentAnimation;
  }

  void Sprite::destroySensor()
  {
    _className.assign("Sprite");
    if (_sensor) {
      delete _sensor;
      _sensor = NULL;
    }
  }

  Shader *Sprite::setShader(Shader *shader)
  {
    _plane->setShader(shader);
    return _plane->getShader();
  }

  Shader *Sprite::getShader()
  {
    return _plane->getShader();
  }

  Plane *Sprite::getPlane()
  {
    return _plane;
  }

  EventHandler Sprite::OnAnimationFinished(Animation *animation)
  {
    if (!(this->EventFlags & EventTypes::OnAnimationFinished)) {
      return;
    }

    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnAnimationFinished");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "Sprite");
    tolua_pushusertype(GameEngine::LUA_STATE, animation, "Animation");

    if (lua_pcall(GameEngine::LUA_STATE, 2, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  EventHandler Sprite::OnAnimationStarted(Animation *animation)
  {
    if (!(this->EventFlags & EventTypes::OnAnimationStarted)) {
      return;
    }

    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnAnimationStarted");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "Sprite");
    tolua_pushusertype(GameEngine::LUA_STATE, animation, "Animation");

    if (lua_pcall(GameEngine::LUA_STATE, 2, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }
} // namespace Aztec