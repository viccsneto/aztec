#pragma once
#include "LuaBinded.h"
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

  class PropertyList : public LuaBinded {
  public:
    /**
    * Clear the list of properties
    */
    void clear();


    /**
    * Adds a property to the list
    *
    * @param property The name of a property that will be added to the object
    * @param value The value of a property that will be added to the object
    * @return The property value added to the list
    */
    const char *add(const char *property, const char *value);

    /**
    * Gets the value of the property represented by the given property name
    *
    * @param property A string representing the property name

    * @return The property value or NULL if inexistent
    */
    const char *get(const char *property);

    /**
    * Gets the value of the property represented by the given index
    *
    * @param index The position of the desired property

    * @return The property value or NULL if inexistent
    */
    const char *at(unsigned int index);


    /**
    * Gets the property name represented by the given index
    *
    * @param index The position of the desired property

    * @return The property name or NULL if inexistent
    */
    const char *getName(unsigned int index);


    /**
    * Gets the position of the given property name represented in the list
    *
    * @param property A string representing the property name
    * @return The position of the desired property in the list
    */
    int getIndex(const char *property);

    /**
    * Gets the position of the first occurrence of the given value represented in the list
    *
    * @param value A string representing the property value
    * @return The position of the desired property in the list
    */
    int getValueIndex(const char *value);

    /**
    * Gets the position of the nth occurrence of the given value represented in the list
    *
    * @param value A string representing the property value
    * @param n The occurrence number that will be searched (e.g.: {"Skill":"Fight", "Weakness":"Water",  "Skill":"Climb"} have two occurences of "Skill" but i might want the position of the second occurrence, so I must pass 2 in the n argument)
    * @return The position of the desired property in the list
    */
    int getValueIndex(const char *value, unsigned int n);

    /**
    * Gets the number of properties assigned to this list
    *
    * @return The number of properties assigned to this list
    */
    unsigned int getSize();

    /**
    * Updates the values of the property represented by the given name
    *
    * @param property The name of a property that will be added to the object
    * @param value The value of a property that will be added to the object
    * @return The property value of the the updated property
    */
    const char *set(const char *property, const char *value);

    /**
    * Removes the property represented by the given name
    *
    * @param property The name of a property that will be removed from the object
    */
    void remove(const char *property);

    /**
    * Detects if the list contains a property
    *
    * @param property The property name that will be checked
    * @return A boolean indicating if the property exists or not in the list
    */
    bool has(const char *property);


    /**
    * Detects if the list contains a property with the given value
    *
    * @param value The property value that will be searched
    * @return A boolean indicating if the a property with the given value exists or not in the list
    */
    bool hasValue(const char *value);

    /*
    * Returns the list of properties represented by this object
    */
    multimap<string, string> getList();
    PropertyList();
    ~PropertyList();

  private:
    multimap<string, string> m_property_map;
  };

} // namespace Aztec