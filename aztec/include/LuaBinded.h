#pragma once
#include <stdlib.h>
#include <string>
using namespace std;

namespace Aztec {
  /**
  * LuaBinded
  *
  * The base class for objects that will be binded to Lua
  * It has the EventFlags field and the correct destructor that will free memory from Lua if the object be deleted direct in C++(destruction not invoked from Lua)
  *
  *
  * \author	Vicente Neto
  *
  */
  class LuaBinded {
  public:
    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * These flags are used to prevent the GameEngine of make unnecessary calls to the Lua Subsystem to objects that are not waiting for
    * those calls.
    * For example, when a object is not waiting for the OnUpdate event(has no OnUpdate event handler), it will be unsigned from the flags after the first attempt of this event delivery.
    */
    long EventFlags;

    /**
    * <DIV class="ah icona">Lua</DIV>
    *
    * Reset event flags so that The engine will search for new handlers (it will be necessary only if the user decides to put a new handler during game execution)
    */
    void resetEventFlags();

    /**
    * Constructor
    */
    LuaBinded();

    /**
    * Destructor
    */
    virtual ~LuaBinded(void);

    /**
    * Returns the the instance class name
    */
    const char *getClassName();

  protected:
    string _className;
  };
}; // namespace Aztec