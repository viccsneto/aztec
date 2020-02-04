#pragma once
#include <list>
#include <map>
#include <Box2D/Box2D.h>
#include "LuaBinded.h"
#include "Camera.h"
#include "GameCanvas.h"
#include "GameObject.h"
#include "ContactFilter.h"
#include "ContactSolver.h"
#include "DebugDraw.h"
#include "EventTypes.h"
#include "PropertyList.h"
#include "GameObjectList.h"
namespace Aztec {
  using namespace std;
  /**
  * Game State Controller
  *
  * Abstract class that represents a state of the game. Each of the states of the
  * game should derive from this class.
  * Its divides the execution of the game in time slices, allowing the programmer
  * to have a firmer grip on what is going to happen on each frame.
  *
  *
  * \author	Vicente Neto
  *
  */
  class GameStateController : public LuaBinded {
  public:
    const unsigned int TILE      = 0;
    const unsigned int BACKDROPS = 1;
    const unsigned int OVERLAY   = 2;

    /**
    * <DIV class="ah icona">Lua</DIV>
    * 
    * Constructor
    */
    GameStateController();

    /**
    * <DIV class="ah icona">Lua</DIV>
    * Constructor
    *
    * Parses and loads a Tiled TMX file to the GameStateController
    */
    GameStateController(const char *tmx_path);

    /**
    * <DIV class="ah icona">Lua</DIV>
    */
    ~GameStateController();
    /**
    * Load
    *
    * this method is called when the state needs to be loaded on memory.
    * Remember to load all your resources for this state.
    */
    void load();

    /**
    * Unload
    *
    * method called when the state need to be discarded from the memory.
    * Remember to deallocate everything here.
    */
    void unload();

    /**
    * Start
    *
    * this method can only be called when the state is already loaded. It is
    * used when a switch in states is necessary but there should be no
    * "reloading" of the resources.
    */
    void start();

    /**
    * Stop
    *
    * this methods brings the state to halt, but it doesn't gets it out of the
    * memory. Provides a fast change of context.
    */
    void stop();

    /**
    * Step
    *
    * This methods allows a firm grip on what will happen within each frame.
    * The application calls this method informing how much time in milliseconds
    * have passed between this and the last frame, to allow time-based
    * animations. In this method the programmer must update the state of all
    * it's relevant game objects and prepare them for rendering.
    *
    */
    void step();

    /**
    * Draw
    *
    * After the step function, the engine calls the draw method. In this method
    * the programmer should order the drawing of the frame.
    */
    void draw();

    /**
    * Is Loaded
    *
    * Answers if the assets of this state is loaded in the main memory.
    */
    bool isLoaded();

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Adds a GameObject to a custom layer
    *
    * @param object the object that will be added
    * @param layer_id the layer id and z-order where the object will be added
    *
    * @return a pointer to the added object
    */
    GameObject *add(GameObject *object, unsigned int layer_id);
    GameObject *add(GameObject *object);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Removes a GameObject from a custom layer
    *
    * @param object the object that will be removed
    * @param layer_id the layer id from where the object will be taken
    *
    * @return a pointer to the removed object
    */
    GameObject *remove(GameObject *object, unsigned int layer_id);

    /**
    * Returns the layer GameObject represented by the given id 
    *
    * @param layer_id A unsigned int representing the layer that is being required
    /*                                                                      */
    GameObject *getLayer(unsigned int layer_id);

    /**
    * Removes a destroying layer from the multimap
    *
    * @param layer_id The id of the layer being destroyed
    */
    void removeLayerReference(unsigned int layer_id);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Adds a GameObject to the topmost default rendering layer(OverLay)
    *
    * @param object the object that will be added
    *
    * @return a pointer to the added object
    */
    GameObject *addOverlay(GameObject *object);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Removes a GameObject from the topmost default rendering layer(OverLay)
    *
    * @param object the object that will be removed
    *
    * @return a pointer to the removed object
    */
    GameObject *removeOverlay(GameObject *object);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Adds a GameObject to the intermediate default rendering layer(BackDrops)
    *
    * @param object the object that will be added
    *
    * @return a pointer to the added object
    */
    GameObject *addBackDrops(GameObject *object);
    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Removes a GameObject from the intermediate rendering layer(BackDrops)
    *
    * @param object the object that will be removed
    *
    * @return a pointer to the removed object
    */
    GameObject *removeBackDrops(GameObject *object);


    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Adds a GameObject to the backmost default rendering layer(Tile)
    *
    * @param object the object that will be added
    *
    * @return a pointer to the added object
    */
    GameObject *addTile(GameObject *object);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Removes a GameObject from the backmost default rendering layer(Tile)
    */
    GameObject *removeTile(GameObject *object);

    /**
    * getWorld
    *
    * Gets the pointer to the Box2D World object associated with this GameState
    *
    *
    * @return a pointer to the physics world
    */
    b2World *getWorld();

    /**
    *
    * Sets the active camera(alternative to the default camera)
    * @param camera A pointer for the camera or NULL if wants to activate the default camera
    */
    void setActiveCamera(Camera *camera);

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Returns a pointer to the active camera
    * @return a Camera pointer
    */
    Camera *getActiveCamera();

    /**
    * <DIV class="ah icona">Lua</DIV>
    * Sets a custom property name/value pair
    *
    * @param property The name of the property being set
    * @param value The value of the property being set
    *
    * @return The value of the property being set
    */

    const char *setProperty(const char *property, const char *value);

    /**
    * <DIV class="ah icona">Lua</DIV>
    * Returns a custom property value
    *
    * @param property The name of the required property
    *
    * @return The value of the required property
    */
    const char *getProperty(const char *property);

    /**
    * <DIV class="ah icona">Lua</DIV>
    * Removes a custom property value
    *
    * @param property The name of the property to be removed
    *
    */
    void removeProperty(const char *property);

    /**
    * <DIV class="ah icona">Lua</DIV>
    * Clear all custom property values
    */
    void clearProperties();

    /**
    * <DIV class="ah icona">Lua</DIV>
    * Gets the value of the property represented by the given index
    *
    * @param index The position of the desired property

    * @return The property value or NULL if inexistent
    */
    const char *propertyAt(unsigned int index);

    /**
    * <DIV class="ah icona">Lua</DIV>
    * Gets the property name represented by the given index
    *
    * @param index The position of the desired property

    * @return The property name or NULL if inexistent
    */
    const char *getPropertyName(unsigned int index);

    /**
    * <DIV class="ah icona">Lua</DIV>
    * Detects if the state contains a property
    *
    * @param property The property name that will be checked
    * @return A boolean indicating if the property exists or not in the list
    */
    bool hasProperty(const char *property);

    /**
    * <DIV class="ah icona">Lua</DIV>
    * Gets the number of properties assigned to this state
    *
    * @return The number of properties assigned to this state
    */
    unsigned int getPropertyCount();

    /**
    * Sets the color of the GameState background
    */
    void setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    /**
    * <DIV class="ah icona">Lua</DIV>
    * Returns a list containing objects that have the given property
    *
    * @param property The property name that will be used as filter for the query
    *
    * @return a GameObjectList containing objects that have the given property
    */
    GameObjectList *queryProperty(const char *property);

    /**
    * <DIV class="ah icona">Lua</DIV>
    * Returns a list containing objects that have the given property
    *
    * @param property The property name that will be used as filter for the query
    * @param value The property value that will be used as filter for the query
    * @return a GameObjectList containing objects that have the given property with the given value
    */
    GameObjectList *queryProperty(const char *property, const char *value);

    /// Events
    virtual inline EventHandler OnLoad();
    virtual inline EventHandler OnUnload();
    virtual inline EventHandler OnStart();
    virtual inline EventHandler OnStop();
    virtual inline EventHandler OnUpdate();
    /// input output
    virtual inline EventHandler OnKeyDown(int keyCode);
    virtual inline EventHandler OnKeyUp(int keyCode);
    virtual inline EventHandler OnMouseDown(int button);
    virtual inline EventHandler OnMouseUp(int button);
    virtual inline EventHandler OnMouseMove();


  private:
    /**
    * Default Camera
    * The default camera for rendering
    */

    /**
    * Clear color
    */
    glm::vec4        _clearColor;
    Camera *         _defaultCamera;
    Camera *         _activeCamera;
    bool             _amLoaded;
    b2World *        _world;
    b2ContactFilter *_contactFilter;
    b2Body *         _mouseBody;
    b2Fixture *      _mouseFixture;
    PropertyList     m_property_list;

    /**
    * createPhysicalWorld
    *
    * Creates the Box2D world object that will be associated with this GameState
    */
    void createPhysicalWorld();

    /**
    * destroyPhysicalWorld
    *
    * deletes the Box2D world object that is associated with this GameState
    */
    void destroyPhysicalWorld();

    /**
    * createMouseSensor
    *
    * Creates the MouseSensor object that will follow the mouse pointer and interact with the physics collision detection subsystem
    */
    void createMouseSensor();

    /**
    * destroyMouseSensor
    *
    * delete the MouseSensor object that  follow the mouse pointer and interact with the physics collision detection subsystem
    */
    void destroyMouseSensor();

    void updatePhysics();

    double __physicsUpdateAccumulator;

  protected:
    void                        parseTMX();
    DebugDraw *                 _debugDraw;
    ContactSolver *             _solver;
    multimap<int, GameObject *> _layers;
    char *                      _tmx_path;
  };
} // namespace Aztec