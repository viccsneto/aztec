#pragma once
#ifndef __CPPLAY_GAMEOBJECT__
#define __CPPLAY_GAMEOBJECT__

#include "Config.h"
#include "LuaBinded.h"
#include "Transform.h"
#include "Vector2.h"
#include "Rectangle.h"
#include "EventTypes.h"
#include "PropertyList.h"
#include <list>
#include <string>
class b2World;
class b2Body;
class b2BodyDef;
class b2CircleShape;
class b2Joint;

namespace Aztec {
  class GameStateController;

  using namespace std;
  /**
  * GameObject
  *
  * The base class that defines a game object in Aztec.
  *
  * \author	Vicente Neto
  *
  */
  class GameObject : public LuaBinded {
  protected:
    GameStateController *m_gamestate;
    bool                 m_object_released;
    bool                 m_painted;

    /**
    * _world
    *
    * The Box2D World that owns this object's body
    */
    b2World *_world;

    /**
    * _body
    *
    * The Box2D physics body for this GameObject
    */
    b2Body *_body;

    /**
    * _clipRect
    *
    * A pointer for the rendering boundary for this GameObject and it's children
    */

    Rectangle *_clipRect;

    /**
    * reScale
    *
    * This is called when the GameObject scale changes so the specific object can handle the changes(like recreate fixtures)
    */
    virtual void reScale();


    /**
    * _oldTransform
    *
    * it is used to compare the current Transform object with the last Transform object.
    * if they differ, then updates the Box2D Body's Transform and rotation values.
    */
    Transform _oldTransform;


  private:
    PropertyList m_property_list;
    int          _zorder;
    unsigned int _layer_id;
    bool         _instantiated;
    double       m_last_click;
    bool         getParentDisabled();

    class enabledGetterSetter : public GETTERSETTER<bool, GameObject> {
      bool setValue(bool v)
      {
        if (_value != v) {
          _value = v;
          _instance->updateEnabled();
        }
        else {
          _value = v;
        }

        return _value;
      }
      bool getValue()
      {
        return _value;
      }
    };

    class xGetterSetter : public GETTERSETTER<float, void> {
      float setValue(float v)
      {

        _value = v;
        ((GameObject *)_instance)->updateTransforms();
        return _value;
      }
    };

    class yGetterSetter : public GETTERSETTER<float, void> {
      float setValue(float v)
      {
        _value = v;
        ((GameObject *)_instance)->updateTransforms();
        return _value;
      }
    };

    class rotationGetterSetter : public GETTERSETTER<float, void> {
      float setValue(float v)
      {
        _value = v;
        ((GameObject *)_instance)->updateTransforms();
        return _value;
      }
    };

    class xScaleGetterSetter : public GETTERSETTER<float, void> {
      float setValue(float v)
      {
        _value = v;
        if (_value <= AZTEC_MINIMUM_SCALE_VALUE) {
          _value = AZTEC_MINIMUM_SCALE_VALUE;
        }
        ((GameObject *)_instance)->reScale();
        return _value;
      }
    };

    class yScaleGetterSetter : public GETTERSETTER<float, void> {
      float setValue(float v)
      {
        _value = v;
        if (_value <= AZTEC_MINIMUM_SCALE_VALUE) {
          _value = AZTEC_MINIMUM_SCALE_VALUE;
        }
        ((GameObject *)_instance)->reScale();
        return _value;
      }
    };

    xGetterSetter *_xGetterSetter;
    yGetterSetter *_yGetterSetter;

    xScaleGetterSetter *_xScaleGetterSetter;
    yScaleGetterSetter *_yScaleGetterSetter;

    rotationGetterSetter *_rotationGetterSetter;

    enabledGetterSetter *_enabledGetterSetter;

    /**
    * _toBeDestroyed
    *
    * Determines if the object must be destroyed after the current gameloop
    */
    bool _toBeDestroyed;

    /**
    * createPhysicalBody
    *
    * Create the Box2D body in association with the contextual GameStateController(that may be loading or running).
    */
    void createPhysicalBody();

    /**
    * destroyPhysicalBody
    *
    * Destroys the Box2D body
    */
    void destroyPhysicalBody();


    /**
    * _bodydef
    *
    * Default body definition for all GameObjects(and it's subclasses)
    */
    static b2BodyDef *_bodydef;

    /**
    * _objectShape
    *
    * Default objectShape(a circle) for all GameObjects(and it's subclasses)
    */
    static b2CircleShape *_objectShape;

  protected:
    /**
    * calculateTransforms
    *
    * Updates the _globalTransform values considering the Global World position of the GameObject's body.
    * This is necessary because Transform is always relative when the object has a parent.
    */
    virtual void calculateTransforms();

    /**
    * _parentJoint
    *
    * Physically connects the GameObject with it's parent.
    */
    b2Joint *_parentJoint;


    /**
    * _parent
    *
    * A pointer to the GameObject that contains this GameObject
    */

    GameObject *_parent;

    /**
    * _pivot
    *
    * Represents the point in space where all transformations will be centered
    */
    Vector2 _pivot;

    /**
    * _globalTransform
    *
    * The global Transformation of the GameObject(considering all parents, if any)
    */
    Transform _globalTransform;

    /**
    * _ownerList
    *
    * A pointer to the list that owns this GameObject(maybe the parent's _children list or one of the GameStateControllers layer's list)
    * It will be used for, on destruction of the GameObject, remove it from the corresponding list
    */
    list<GameObject *> *_ownerList;

    /**
    * _children
    *
    * A list of GameObjects that are connected as childs of this GameObject
    */
    list<GameObject *> _children;

    /**
    * _toBeAdded
    *
    * A list of GameObjects that will be added as child of this GameObject after the current step
    * This is necessary because during the current step the _children list will be iterated.
    */
    list<GameObject *> _toBeAdded;


    /**
    * drawChildren
    *
    * iterates over the _children list calling each of the child's draw method
    */
    void drawChildren();

    /**
    * beginClipRect
    *
    * Set up the clipping boundary of the GameObject and it's children using OpenGL Stencil Buffer
    */
    void beginClipRect();

    /**
    * endClipRect
    *
    * Removes the clipping rectangle when the GameObject and all of it's children were rendered
    */
    void endClipRect();

  public:
    /**
    * addPendentObjects
    *
    * Move the objects from _toBeAdded list to the _children list at the end of the current step
    */
    void addPendentObjects();

    int getZOrder()
    {
      return _zorder;
    }

    int setZOrder(int value)
    {
      _zorder            = value;
      GameObject *parent = getParent();
      if (parent) {
        parent->removeGameObject(this);
        parent->addGameObject(this);
      }
      return _zorder;
    }
    /**
    * Sets a custom property name/value pair
    * 
    * @param property The name of the property being set
    * @param value The value of the property being set
    *
    * @return The value of the property being set
    */

    const char *setProperty(const char *property, const char *value);
    const char *setProperty(const char *property);

    /**
    * Returns a custom property value 
    *
    * @param property The name of the required property
    *
    * @return The value of the required property
    */
    const char *getProperty(const char *property);

    /**
    * Removes a custom property value
    *
    * @param property The name of the property to be removed
    *    
    */
    void removeProperty(const char *property);

    /**
    * Clear all custom property values
    *
    */
    void clearProperties();

    /**
    * Gets the value of the property represented by the given index
    *
    * @param index The position of the desired property

    * @return The property value or NULL if inexistent
    */
    const char *propertyAt(unsigned int index);

    /**
    * Gets the property name represented by the given index
    *
    * @param index The position of the desired property

    * @return The property name or NULL if inexistent
    */
    const char *getPropertyName(unsigned int index);

    /**
    * Detects if the list contains a property
    *
    * @param property The property name that will be checked
    * @return A boolean indicating if the property exists or not in the list
    */
    bool hasProperty(const char *property);

    /**
    * Gets the number of properties assigned to this GameObject
    *
    * @return The number of properties assigned to this GameObject
    */
    unsigned int getPropertyCount();


    void updateEnabled();
    /**
    * updateTransforms
    *
    * Update the _globalTransform values according to the Box2D body properties
    */
    void updateTransforms();

    /**
    * insideCameraBounds
    *
    * Says if the GameObject is inside the active camera rendering frame.
    * If not, then step over the rendering process(a simplified culling system)
    */
    bool insideCameraBounds;

    /**
    * mouseOver
    *
    * Says if the GameObject is in contact with the mouse cursor.
    * It is necessary to dispatch mouse events only to the object that actually are in mouse range.
    */
    bool mouseOver;

    /**
    * <DIV class="ah icona">Lua</DIV>
    */
    GameObject();

    /**
    * <DIV class="ah icona">Lua</DIV>
    */
    virtual ~GameObject();

    /**
    * This method should implement the update routine of the GameObject, such
    * as animations and motion.
    */
    virtual void step();

    /**
    * This method draws the GameObject on its position on the canvas
    */
    virtual void draw();

    /**
    * This function must load all the needed resources.
    */
    virtual void load();

    /**
    * unload everything you loaded on Load.
    */
    virtual void unload();

    /**
    * setParent
    *
    * Sets the GameObject that is the parent of the object in a parent/children/aggregation paradigm
    *
    * @param obj a pointer to the GameObject that will be set as parent of this object
    */
    void setParent(GameObject *obj);

    /**
    * setClipRect
    *
    * Initializes the clipping boundary of the GameObject (are within the GameObject can be drawn)
    * @param rect A Rectangle pointer that will represent the clipping boundary of the GameObject (area within the GameObject can be drawn)
    */
    void setClipRect(Rectangle *rect);

    /**
    * getBody
    *
    * Return a reference to the Box2D physical body of this GameObject
    * @return a b2Body pointer
    */
    b2Body *getBody();

    /**
    * getClipRect
    *
    * @return A pointer to the CRetangle that represents the GameObject's clipping boundary.
    */
    Rectangle *getClipRect();

    /**
    * setOwnerList
    *
    * Sets a reference for the list in where the GameObject is inserted.
    * The object will then remove itself from this list when necessary(when being destroyed or added to another list)
    */

    void setOwnerList(list<GameObject *> *lst);

    /**
    * getOwnerList
    *
    * Returns a pointer to the list in where the GameObject is inserted.
    * @return a list<GameObject *> pointer
    */
    list<GameObject *> *getOwnerList();

    /**
    * insertion_sort
    *
    * A insertion_sort like algorithm that insert the GameObject in a list considering it's Transform.zorder value
    */
    static void insertion_sort(list<GameObject *> *lst, GameObject *object)
    {

      if (lst->empty()) {
        lst->push_front(object);
      }
      else {
        //get the values that will be used to determine where is the better position to insert the object
        float backZ   = lst->front()->getZOrder();
        float frontZ  = lst->back()->getZOrder();
        float objectZ = object->getZOrder();

        //if the frontmost element is less or equal than the new one, them put the new one in front of it
        if (frontZ <= objectZ) {
          lst->push_back(object);
        }
        else if (backZ >= objectZ) //if the backmost element is greater or equal than the new one, them put the new one in back of it
        {
          lst->push_front(object);
        }
        else {
          //must decide where is the best approach for insertion sort(from the begin or from the end?!)

          if (abs(objectZ - backZ) <= abs(frontZ - objectZ)) {
            //guess it is best to start from the begin
            for (list<GameObject *>::iterator i = lst->begin(); i != lst->end(); ++i) {

              //insert the element here
              if ((*i)->getZOrder() >= objectZ) {
                lst->insert(i, object);
                break;
              }
            }
          }
          else {
            //guess it is best to start from the end
            for (list<GameObject *>::iterator i = --lst->end(); i != lst->begin(); --i) {
              //insert the element here
              if ((*i)->getZOrder() <= objectZ) {
                lst->insert(++i, object);
                break;
              }
            }
          }
        }
      }
    }

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Represents a object that describes and manipulate GameObject's position, scale, rotation and Z-order
    */

    Aztec::Transform Transform;

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Determines if the GameObject(and it's children) will be drawn on the screen
    */
    bool Visible;

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Determines if the GameObject(and it's children) will "step" during the next iteration
    */
    BooleanProperty<GameObject> Enabled;

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Retuns the Global Position of the GameObject (Considering its local position and the positions of all parents)
    *
    * @return a Transform representing the global position of the GameObject
    */
    Aztec::Transform getGlobalTransform();


    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Gets the parent of the object.
    *
    * @return the GameObject that is the parent of this object(or NULL in case there is not a parent)
    */
    GameObject *getParent();

    /**
    * <DIV class="ah icona">Lua</DIV>
    * Adds a new child into the GameObject.
    *
    * @param object a GameObject to be added as child of the object.
    * @return a pointer to the added object
    */
    GameObject *addGameObject(GameObject *object);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Remove a child of the GameObject
    * @param object the GameObject that will be removed from the object.
    * @return a pointer to the removed object
    */
    GameObject *removeGameObject(GameObject *object);


    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Sets the origin(center) of the GameObject.
    * @param x the x position of the origin
    * @param y the y position of the origin
    */
    void setPivot(float x, float y);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Gets the origin of the GameObject.
    * @result a Vector2 representing the origin of the sprite
    */
    Vector2 getPivot();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Initializes the clipping boundary of the GameObject (area within the GameObject can be drawn)
    *
    * @param x The x position of the rectangle
    * @param y The y position of the rectangle
    * @param w The width of the rectangle (0 deactivates the clipRect)
    * @param h The height of the rectangle (0 deactivates the clipRect)
    */
    void setClipRect(float x, float y, float w, float h);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * mark the object for destruction after the current GameLoop iteration
    */
    void destroy();

    /**
    * Called from GameStateController when a new layer, represented by this GameObject is created
    * It is for the case that the user decides to destroy the layer
    */
    void setLayerID(unsigned int layer_id);

    /**
    * Returns the layer_id of the object    
    */
    unsigned int getLayerID();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Returns the layer of the object or itself in the case the object is a layer
    * UINT32_MAX otherwise
    */
    GameObject *getLayer();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Indicates if this GameObject represents a layer for the GameStateController    
    */
    bool isLayer();


    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Returns the GameStateController that represents this GameObject context
    *
    */
    GameStateController *getGameState();

    const list<GameObject *> getChildren() const;
    ///Events

    virtual inline EventHandler OnAfterDraw();
    virtual inline EventHandler OnBeforeDraw();
    virtual inline EventHandler OnBeginContact(GameObject *b);
    virtual inline EventHandler OnEndContact(GameObject *b);
    virtual inline EventHandler OnClick();
    virtual inline EventHandler OnMouseMove();
    virtual inline EventHandler OnCreate();
    virtual inline EventHandler OnDestroy();
    virtual inline EventHandler OnUpdate();
  };
} // namespace Aztec
#endif