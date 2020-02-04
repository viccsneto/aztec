#pragma once
#include "LuaBinded.h"
#include "GameObject.h"
#include <map>
#include <string.h>

namespace Aztec {
  using namespace std;
  /**
  * Represents a list of Property
  *
  * It is very useful and more intuitive to define polygons adding property by property instead
  * of passing an array of values
  * It turn the process of passing such kind of list from the Lua Context to C++ into a
  * more concrete operation
  */

  class GameObjectList : public LuaBinded {
  public:
    /**
    * Clear the list of properties
    */
    void clear();


    /**
    * Adds a GameObject to the list
    *
    * @param object A GameObject that will be inserted into the list
    * @return The property value added to the list
    */
    GameObject *add(GameObject *object);

    /**
    * Gets a GameObject at the given index
    *
    * @param index The position of the desired GameObject

    * @return The GameObject or NULL if inexistent
    */
    GameObject *get(unsigned int index);

    /**
    * Gets the GameObject represented by the given index (same as get to prevent confusion if compared to the PropertyList API)
    *
    * @param index The position of the desired GameObject

    * @return The GameObject or NULL if inexistent
    */
    GameObject *at(unsigned int index);


    /**
    * Gets the number of properties assigned to this list
    *
    * @return The number of properties assigned to this list
    */
    unsigned int getSize();

    /**
    * Removes the GameObject from the list
    *
    * @param object The GameObject that will be removed from the list
    */
    void remove(GameObject *object);

    /**
    * Detects if the list contains a GameObject
    *
    * @param object The GameObject that will be searched in the list
    * @return A boolean indicating if the object exists or not in the list
    */
    bool has(GameObject *object);

    /**
    * Sets the index position of the list
    * It allows to iterate the list using next() calls
    *
    * @param pos the desired position of the list
    *
    * @return A bool indicating if the position could be set
    */
    bool setPosition(unsigned int pos);

    /**
    * Indicates if the list have more objects
    * @return A bool indicating if the next object can be retrieved
    */
    bool hasNext();

    /**
    * Retrieves the next object of the list 
    * @return The next GameObject or NULL if inexistent
    */
    GameObject *next();
    /*
    * Returns the list of GameObjects in the list
    * @return The GameObject or NULL if inexistent
    */
    multimap<GameObject *, GameObject *> getList();
    GameObjectList();
    ~GameObjectList();

  private:
    multimap<GameObject *, GameObject *> m_gameobject_map;
    int                                  m_index;
  };

} // namespace Aztec