#include "GameEngine.h"
#include "GameObject.h"
#include <iostream>
#include "EventTypes.h"
#include "EventDispatcher.h"
#include "Config.h"
#include "GameStateController.h"
#include "PropertyManager.h"
#include <math.h>
#include <Box2D/Box2D.h>

namespace Aztec {
  b2BodyDef *    GameObject::_bodydef     = NULL;
  b2CircleShape *GameObject::_objectShape = NULL;

  GameObject::GameObject()
  {
    _className.assign("GameObject");
    m_gamestate    = GameEngine::getInstance()->getContextGameState();
    m_last_click   = 0;
    _zorder        = 0;
    _layer_id      = UINT32_MAX;
    _instantiated  = false;
    _toBeDestroyed = false;

    mouseOver = false;

    _clipRect    = NULL;
    _parent      = NULL;
    _parentJoint = NULL;
    _ownerList   = NULL;
    createPhysicalBody();

    Visible = true;

    _xGetterSetter = new xGetterSetter();
    _yGetterSetter = new yGetterSetter();

    _xScaleGetterSetter = new xScaleGetterSetter();
    _yScaleGetterSetter = new yScaleGetterSetter();

    _rotationGetterSetter = new rotationGetterSetter();

    _enabledGetterSetter = new enabledGetterSetter();

    Transform.position.x.Initialize(_xGetterSetter, this);
    Transform.position.y.Initialize(_yGetterSetter, this);
    Transform.scale.x.Initialize(_xScaleGetterSetter, this);
    Transform.scale.y.Initialize(_yScaleGetterSetter, this);
    Transform.rotation.Initialize(_rotationGetterSetter, this);
    Enabled.Initialize(_enabledGetterSetter, this);
    Enabled = true;
  }

  GameObject::~GameObject()
  {


    for (list<GameObject *>::iterator i = _toBeAdded.begin(); i != _toBeAdded.end(); ++i) {
      delete (*i);
    }

    for (list<GameObject *>::iterator i = _children.begin(); i != _children.end(); ++i) {
      delete (*i);
    }


    delete _xGetterSetter;
    delete _yGetterSetter;
    delete _xScaleGetterSetter;
    delete _yScaleGetterSetter;
    delete _rotationGetterSetter;


    delete _enabledGetterSetter;

    destroyPhysicalBody();
  }

  void GameObject::reScale()
  {

    float dx = 1;
    float dy = 1;

    if (_oldTransform.scale.x != 0) {
      dx = Transform.scale.x / _oldTransform.scale.x;
    }


    if (_oldTransform.scale.y != 0) {
      dy = Transform.scale.y / _oldTransform.scale.y;
    }

    if (dx != 1.0f || dy != 1.0f) {

      if (dx != 1.0f) {
        for (list<GameObject *>::iterator i = _children.begin(); i != _children.end(); ++i) {
          (*i)->Transform.position.x = ((*i)->Transform.position.x * dx);
          (*i)->Transform.scale.x    = ((*i)->Transform.scale.x * dx);
        }


        for (list<GameObject *>::iterator i = _toBeAdded.begin(); i != _toBeAdded.end(); ++i) {
          (*i)->Transform.position.x = ((*i)->Transform.position.x * dx);
          (*i)->Transform.scale.x    = ((*i)->Transform.scale.x * dx);
        }
        if (_clipRect) {
          _clipRect->w *= dx;
        }
        _oldTransform.scale.x = Transform.scale.x;
      }

      if (dy != 1.0f) {
        for (list<GameObject *>::iterator i = _children.begin(); i != _children.end(); ++i) {
          (*i)->Transform.position.y = ((*i)->Transform.position.y * dy);
          (*i)->Transform.scale.y    = ((*i)->Transform.scale.y * dy);
        }


        for (list<GameObject *>::iterator i = _toBeAdded.begin(); i != _toBeAdded.end(); ++i) {
          (*i)->Transform.position.y = ((*i)->Transform.position.y * dy);
          (*i)->Transform.scale.y    = ((*i)->Transform.scale.y * dy);
        }
        if (_clipRect) {
          _clipRect->h *= dy;
        }

        _oldTransform.scale.y = Transform.scale.y;
      }

      _globalTransform.scale.assign(Transform.scale);
    }
  }

  void GameObject::calculateTransforms()
  {
    _globalTransform.rotation   = -_body->GetAngle() * RADIAN_TO_DEGREE;
    _globalTransform.position.x = _body->GetPosition().x * Config::PHYSICS_PIXELS_METERS_RATIO;
    _globalTransform.position.y = _body->GetPosition().y * Config::PHYSICS_PIXELS_METERS_RATIO;
  }

  void GameObject::step()
  {

    addPendentObjects();

    if (!Enabled) {
      _body->SetActive(false);
      return;
    }
    else {
      _body->SetActive(true);
    }

    updateTransforms();

    EventDispatcher::doUpdateEvent(this);

    if (mouseOver) {
      if (Mouse::hasMovement) {
        EventDispatcher::registerForMouseMove(this);
      }

      if (Mouse::hasClick) {
        EventDispatcher::registerForMouseClick(this);
      }
    }

    if (!_children.empty()) {
      for (list<GameObject *>::iterator i = _children.begin(); i != _children.end(); ++i) {
        (*i)->step();
      }
    }
  }

  void GameObject::updateTransforms()
  {
    if (_parent != NULL) {
      _body->SetTransform(
          _parent->getBody()->GetWorldPoint(b2Vec2(Transform.position.x / Config::PHYSICS_PIXELS_METERS_RATIO, Transform.position.y / Config::PHYSICS_PIXELS_METERS_RATIO)),
          (Transform.rotation * DEGREE_TO_RADIAN) + _parentJoint->GetBodyA()->GetAngle());
    }
    else {
      _body->SetTransform(b2Vec2(Transform.position.x / Config::PHYSICS_PIXELS_METERS_RATIO, Transform.position.y / Config::PHYSICS_PIXELS_METERS_RATIO),
                          Transform.rotation * DEGREE_TO_RADIAN);
    }

    _oldTransform.position.assign(Transform.position);
    _oldTransform.rotation = Transform.rotation;
    calculateTransforms();
  }

  void GameObject::drawChildren()
  {
    if (!_children.empty()) {
      for (list<GameObject *>::iterator i = _children.begin(); i != _children.end(); ++i) {
        (*i)->draw();
      }
    }
  }

  void GameObject::draw()
  {

    if (!Visible) {
      return;
    }


    beginClipRect();
    drawChildren();
    endClipRect();
  }

  void GameObject::load()
  {
  }

  void GameObject::unload()
  {
  }

  Transform GameObject::getGlobalTransform()
  {
    return _globalTransform;
  }

  void GameObject::setParent(GameObject *obj)
  {

    if (_parentJoint != NULL) {
      _world->DestroyJoint(_parentJoint);
      _parentJoint = NULL;
    }

    if (obj != NULL) {
      //obj->updateTransforms();
      _layer_id = obj->getLayerID();
      b2RevoluteJointDef jointDef;
      jointDef.Initialize(
          obj->getBody(), _body,
          obj->getBody()->GetWorldPoint(b2Vec2(Transform.position.x / Config::PHYSICS_PIXELS_METERS_RATIO, Transform.position.y / Config::PHYSICS_PIXELS_METERS_RATIO)));

      jointDef.collideConnected = false;
      jointDef.enableLimit      = true;
      jointDef.lowerAngle       = 0;
      jointDef.upperAngle       = 0;

      _parentJoint = _world->CreateJoint(&jointDef);
      _body->ResetMassData();
    }

    _parent = obj;
  }

  GameObject *GameObject::getParent()
  {
    return _parent;
  }

  GameObject *GameObject::addGameObject(GameObject *object)
  {
    if ((object == NULL) || (object == this)) {
      return NULL;
    }

    object->setOwnerList(&_toBeAdded);
    object->setParent(this);
    _toBeAdded.push_front(object);
    updateTransforms();
    return object;
  }

  void GameObject::addPendentObjects()
  {
    list<GameObject *> pendent;

    for (list<GameObject *>::iterator i = _toBeAdded.begin(); i != _toBeAdded.end(); ++i) {
      pendent.push_front((*i));
    }

    for (list<GameObject *>::iterator i = pendent.begin(); i != pendent.end(); ++i) {
      GameObject *obj = (*i);
      insertion_sort(&_children, obj);
      (*i)->setParent(this);
      (*i)->setOwnerList(&_children);
    }

    _toBeAdded.clear();
  }

  GameObject *GameObject::removeGameObject(GameObject *object)
  {
    if (object == NULL) {
      return NULL;
    }

    if (object->getOwnerList() == &_children) {
      object->setParent(NULL);
      object->setOwnerList(NULL);
    }
    return object;
  }


  void GameObject::setPivot(float x, float y)
  {
    _pivot.set(x, y);
  }

  Vector2 GameObject::getPivot()
  {
    return _pivot;
  }

  void GameObject::setOwnerList(list<GameObject *> *lst)
  {
    if (_toBeDestroyed) {
      return;
    }

    if (_ownerList != NULL) {
      ResourceManager::registerForRemove(this);
    }
    else {
      if (!_instantiated) {
        _instantiated = true;
        updateEnabled();
        EventDispatcher::doOnCreate(this);
      }
    }
    _ownerList = lst;
    updateTransforms();
  }

  list<GameObject *> *GameObject::getOwnerList()
  {
    return _ownerList;
  }

  void GameObject::setClipRect(Rectangle *rect)
  {
    if (_clipRect) {
      delete _clipRect;
    }

    _clipRect = rect;
  }

  void GameObject::setClipRect(float x, float y, float w, float h)
  {
    Rectangle *rect = new Rectangle(x, y, w, h);

    setClipRect(rect);
  }

  Rectangle *GameObject::getClipRect()
  {
    return _clipRect;
  }

  void GameObject::destroy()
  {
    if (!_toBeDestroyed) {
      clearProperties();
      if (isLayer()) {
        m_gamestate->removeLayerReference(_layer_id);
      }
      _toBeDestroyed = true;
      ResourceManager::registerForDestruction(this);
      EventDispatcher::doOnDestroy(this);
    }
  }

  bool issorted(list<GameObject *> *lst)
  {
    float last = lst->front()->Transform.zorder;
    float current;
    for (list<GameObject *>::iterator i = ++lst->begin(); i != lst->end(); ++i) {
      current = (*i)->Transform.zorder;
      if (current < last) {
        return false;
      }

      last = (*i)->Transform.zorder;
    }
    return true;
  }


  void GameObject::beginClipRect()
  {
    EventDispatcher::doBeforeDraw(this);

    if (_clipRect) {
      Rectangle *rect = new Rectangle(_globalTransform.position.x + _pivot.x + _clipRect->x, _globalTransform.position.y + _pivot.y + _clipRect->y, _clipRect->w, _clipRect->h);
      GameEngine::getInstance()->getGameCanvas()->pushClipRect(rect);
    }
  }

  void GameObject::endClipRect()
  {

    if (_clipRect) {
      delete GameEngine::getInstance()->getGameCanvas()->popClipRect();
    }
    EventDispatcher::doAfterDraw(this);
  }

  b2Body *GameObject::getBody()
  {
    return _body;
  }

  void GameObject::setLayerID(unsigned int layer_id)
  {
    _layer_id = layer_id;
  }

  unsigned int GameObject::getLayerID()
  {
    return _layer_id;
  }

  GameObject *GameObject::getLayer()
  {
    if (isLayer())
      return this;
    return getGameState()->getLayer(_layer_id);
  }

  bool GameObject::isLayer()
  {
    return _parent == NULL;
  }

  GameStateController *GameObject::getGameState()
  {
    return m_gamestate;
  }

  void GameObject::destroyPhysicalBody()
  {
    if (_body != NULL) {
      if (_parentJoint != NULL) {
        _world->DestroyJoint(_parentJoint);
        _parentJoint = NULL;
      }
      _body->SetUserData(NULL);
      _body->GetWorld()->DestroyBody(_body);
      _body = NULL;
    }
  }

  void GameObject::createPhysicalBody()
  {

    if (_bodydef == NULL) {
      _bodydef       = new b2BodyDef();
      _bodydef->type = b2BodyType::b2_kinematicBody;

      _bodydef->allowSleep = true;
      _bodydef->position.x = 0;
      _bodydef->position.y = 0;
      _bodydef->active     = false;

      _objectShape           = new b2CircleShape();
      _objectShape->m_radius = GAMEOBJECT_CIRCLE_RADIUS;
      _objectShape->m_p.x    = 0;
      _objectShape->m_p.y    = 0;
    }

    _world = m_gamestate->getWorld();
    _body  = _world->CreateBody(_bodydef);


    b2Fixture *fixture = _body->CreateFixture(_objectShape, 0);


    b2Filter filter;
    filter.categoryBits = ContactFilter::FilterFlags::NONE;

    filter.maskBits = ContactFilter::FilterFlags::NONE;

    fixture->SetSensor(true);
    fixture->SetFilterData(filter);
    _body->SetUserData(this);
  }
  const char *GameObject::setProperty(const char *property)
  {
    return setProperty(property, "");
  }

  const char *GameObject::setProperty(const char *property, const char *value)
  {
    PropertyManager::getInstance()->set_property(this, property, value);
    return m_property_list.set(property, value);
  }

  const char *GameObject::getProperty(const char *property)
  {
    return m_property_list.get(property);
  }

  void GameObject::removeProperty(const char *property)
  {
    PropertyManager::getInstance()->delete_property(this, property);
    m_property_list.remove(property);
  }

  void GameObject::clearProperties()
  {
    if (m_property_list.getSize() > 0) {
      PropertyManager::getInstance()->delete_gameobject(this);
      m_property_list.clear();
    }
  }

  const char *GameObject::propertyAt(unsigned int index)
  {
    return m_property_list.at(index);
  }

  const char *GameObject::getPropertyName(unsigned int index)
  {
    return m_property_list.getName(index);
  }

  bool GameObject::hasProperty(const char *property)
  {
    return m_property_list.has(property);
  }


  unsigned int GameObject::getPropertyCount()
  {
    return m_property_list.getSize();
  }

  bool GameObject::getParentDisabled()
  {
    if (_parent != NULL) {
      return _parent->getParentDisabled();
    }

    return !Enabled;
  }

  void GameObject::updateEnabled()
  {

    if (!Enabled || getParentDisabled()) {
      _body->SetActive(false);
    }
    else {
      _body->SetActive(true);
    }
    updateTransforms();
    for (list<GameObject *>::iterator i = _children.begin(); i != _children.end(); ++i) {
      (*i)->updateEnabled();
    }
  }


  EventHandler GameObject::OnAfterDraw()
  {
    if (!(this->EventFlags & EventTypes::OnAfterDraw)) {
      return;
    }

    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnAfterDraw");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameObject");

    if (lua_pcall(GameEngine::LUA_STATE, 1, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }
  EventHandler GameObject::OnBeforeDraw()
  {
    if (!(this->EventFlags & EventTypes::OnBeforeDraw)) {
      return;
    }

    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnBeforeDraw");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameObject");

    if (lua_pcall(GameEngine::LUA_STATE, 1, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  const list<GameObject *> GameObject::getChildren() const
  {
    return _children;
  }

  EventHandler GameObject::OnBeginContact(GameObject *b)
  {
    if (!(this->EventFlags & EventTypes::OnBeginContact)) {
      return;
    }
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnBeginContact");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameObject");
    tolua_pushusertype(GameEngine::LUA_STATE, b, "GameObject");

    if (lua_pcall(GameEngine::LUA_STATE, 2, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  EventHandler GameObject::OnEndContact(GameObject *b)
  {
    if (!(this->EventFlags & EventTypes::OnEndContact)) {
      return;
    }
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnEndContact");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameObject");
    tolua_pushusertype(GameEngine::LUA_STATE, b, "GameObject");

    if (lua_pcall(GameEngine::LUA_STATE, 2, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  EventHandler GameObject::OnClick()
  {
    double current_time = GameEngine::getInstance()->getCurrentTime();

    if (current_time - m_last_click < CLICK_INTERVAL)
      return;

    m_last_click = current_time;
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnClick");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameObject");
    tolua_pushusertype(GameEngine::LUA_STATE, GameEngine::getInstance()->getMouse(), "Mouse");

    if (lua_pcall(GameEngine::LUA_STATE, 2, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  EventHandler GameObject::OnMouseMove()
  {
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnMouseMove");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameObject");
    tolua_pushusertype(GameEngine::LUA_STATE, GameEngine::getInstance()->getMouse(), "Mouse");

    if (lua_pcall(GameEngine::LUA_STATE, 2, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA ERROR: %s", lua_tostring(GameEngine::LUA_STATE, -1));
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  EventHandler GameObject::OnCreate()
  {
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnCreate");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameObject");

    if (lua_pcall(GameEngine::LUA_STATE, 1, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  EventHandler GameObject::OnDestroy()
  {
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnDestroy");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameObject");

    if (lua_pcall(GameEngine::LUA_STATE, 1, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  EventHandler GameObject::OnUpdate()
  {
    if (!(this->EventFlags & EventTypes::OnUpdate)) {
      return;
    }

    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnUpdate");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameObject");

    if (lua_pcall(GameEngine::LUA_STATE, 1, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }
} // namespace Aztec
