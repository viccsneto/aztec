#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;
namespace Aztec {

  /**
  * GETTERSETTER
  *
  * A template for a getter/setter that will be used in the Property templates
  *
  * @tparam T the type of the value that will be treated by the getter/setter
  * @tparam S the type of the instance that will be accessed when subclassing the getter/setter to access external members
  *
  * \author	Vicente Neto
  *
  */
  template <class T, class S> class GETTERSETTER {
  protected:
    T  _value;
    S *_instance;

  public:
    /**
    * CanRead
    *
    * Detemines if the value can be read
    */
    bool CanRead;

    /**
    * CanWrite
    *
    * Detemines if the value can be written
    */
    bool CanWrite;

    /**
    * NOT_READABLE
    *
    * Exception thrown when attempt to read a not readable value
    */
    class NOT_READABLE {
    };

    /**
    * getValue
    *
    * returns the value of the Property
    * it is largely used by the Property classes overloaded operators.
    *
    * @return the value of the Property which the getter/setter is associated
    */
    virtual T getValue()
    {
      if (!CanRead) {
        throw(NOT_READABLE());
      }

      return _value;
    }

    /**
    * NOT_READABLE
    *
    * Exception thrown when attempt to write a not writable value
    */
    class NOT_WRITABLE {
    };

    /**
    * setValue
    *
    * sets the new value of the Property
    * it is largely used by the Property classes overloaded operators.
    *
    * @return the new value of the Property which the getter/setter is associated
    */
    virtual T setValue(T value)
    {
      if (!CanWrite) {
        throw(NOT_WRITABLE());
      }

      return (_value = value);
    }

    /**
    * Constructor
    *
    * @tparam T the type of the value that will be treated by the getter/setter
    * @tparam S the type of the instance that will be accessed when subclassing the getter/setter to access external members
    */
    GETTERSETTER<T, S>()
    {
      _value    = 0;
      CanRead   = true;
      CanWrite  = true;
      _instance = NULL;
    }

    /**
    * setInstance
    *
    * Sets the instance that will member subclasses of the getter/setter
    */
    void setInstance(S *instance)
    {
      _instance = instance;
    }

    /**
    * rawset
    *
    * Sets the value directly(without calling overriden setValue methods and bypassing CanWrite exceptions)
    *
    * @param value The new value associated with the getter/setter
    * @return The new value of associated with the getter/setter
    */
    T rawset(T value)
    {
      return (_value = value);
    }

    /**
    * rawget
    *
    * Gets the value directly(without calling overriden getValue methods and bypassing CanRead exceptions)
    *
    * @return The value of associated with the getter/setter
    */
    T rawget()
    {
      return _value;
    }
  };


  /**
  * NumericProperty
  *
  * Provides getter/setter functionality to member values.
  * It is very important for the Transform/Vector2 classes because GameObject states has to be updated imediatelly when new property values are entered
  * such as position and scale
  *
  * @tparam T the numeric type of the property
  *
  * @tparam S the type of the instance class that will hold the Property (necessary for subclassed getters/setters)
  */
  template <class T, class S> class NumericProperty {
  protected:
    S *                 _instance;
    GETTERSETTER<T, S> *_gettersetter;

  public:
    /**
    * rawset
    *
    * Sets the value directly(without calling overriden setValue methods and bypassing CanWrite exceptions)
    *
    * @param value The new value associated with the getter/setter
    * @return The new value of associated with the getter/setter
    */
    T rawset(T value)
    {
      return _gettersetter->rawset(value);
    }

    /**
    * rawget
    *
    * Gets the value directly(without calling overriden getValue methods and bypassing CanRead exceptions)
    *
    * @return The value of associated with the getter/setter
    */
    T rawget()
    {
      return _gettersetter->rawget();
    }

    /**
    * Constructor
    */
    NumericProperty()
    {
      _instance     = NULL;
      _gettersetter = new GETTERSETTER<T, S>();
    }


    T operator=(T v)
    {
      return (T)_gettersetter->setValue(v);
    }

    T operator=(NumericProperty<T, S> v)
    {
      return _gettersetter->setValue((T)v);
    }

    operator T()
    {
      return _gettersetter->getValue();
    }

    T operator/(T v)
    {
      return (_gettersetter->getValue() / v);
    }

    T operator*(T v)
    {
      return (_gettersetter->getValue() * v);
    }

    T operator-(T v)
    {
      return (_gettersetter->getValue() - v);
    }

    T operator+(T v)
    {
      return (_gettersetter->getValue() + v);
    }

    T operator+=(T v)
    {
      return _gettersetter->setValue((_gettersetter->getValue() + v));
    }

    T operator-=(T v)
    {
      return _gettersetter->setValue((_gettersetter->getValue() - v));
    }

    T operator*=(T v)
    {
      return _gettersetter->setValue((_gettersetter->getValue() * v));
    }

    T operator/=(T v)
    {
      return _gettersetter->setValue((_gettersetter->getValue() / v));
    }

    T operator++()
    {
      return _gettersetter->setValue((_gettersetter->getValue() + 1));
    }

    T operator--()
    {
      return _gettersetter->setValue(_gettersetter->getValue() - 1);
    }

    /**
    * Initialize
    *
    * Initialize the property with subclassed getter/setter that are members of the instance class
    *
    * @param g a pointer to the getter/setter associated with the instance
    *
    * @param instance a pointer to the instance that hold the property value
    */
    void Initialize(GETTERSETTER<T, S> *g, S *instance)
    {
      g->setInstance(instance);

      if (_gettersetter) {
        g->setValue(_gettersetter->getValue());
        delete _gettersetter;
      }
      _gettersetter = g;
      _instance     = instance;
    }
  };

  template <class S> class BooleanProperty {
  protected:
    S *                    _instance;
    GETTERSETTER<bool, S> *_gettersetter;

  public:
    BooleanProperty()
    {
      _instance     = NULL;
      _gettersetter = NULL;
    }

    bool operator=(bool v)
    {
      return _gettersetter->setValue(v);
    }

    bool operator=(BooleanProperty<S> v)
    {
      return _gettersetter->setValue((T)v);
    }

    operator bool()
    {
      return _gettersetter->getValue();
    }

    void Initialize(GETTERSETTER<bool, S> *g, S *instance)
    {
      g->setInstance(instance);

      if (_gettersetter) {
        g->setValue(_gettersetter->getValue());
        delete _gettersetter;
      }
      _gettersetter = g;
      _instance     = instance;
    }
  };
}; // namespace Aztec