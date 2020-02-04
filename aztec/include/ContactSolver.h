#pragma once
#include <Box2D/Box2D.h>
#include "GameObject.h"

namespace Aztec {
  /**
  * ContactSolver
  *
  * Solve what to do when collisions occurs.
  * This will dispatch events such as OnBeginContact, OnEndContact to the LuaSubSystem,
  * mark objects to be rendered(culling) when in range of active camera and tracks if
  * the objects are under contact with the mouse cursor.
  *
  * \author	Vicente Neto
  */
  class ContactSolver : public b2ContactListener {
  public:
    /**
    * Occurs when two objects starts colliding
    *
    * @param contact A pointer to the b2Contact object representing the contact 
    */
    void BeginContact(b2Contact *contact);

    /**
    * Occurs when there two objects that was in contact separates
    *
    * @param contact A pointer to the b2Contact object representing the contact that was terminated
    */
    void EndContact(b2Contact *contact);
  };


} // namespace Aztec