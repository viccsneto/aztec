#include <tolua.h>
#include "LuaBinded.h"
#include "GameEngine.h"
#include "EventTypes.h"

namespace Aztec {
  void LuaBinded::resetEventFlags()
  {
    EventFlags = EventTypes::ALL;
  }

  LuaBinded::LuaBinded()
  {
    _className.assign("LuaBinded");
    resetEventFlags();
  }

  LuaBinded::~LuaBinded(void)
  {
    tolua_release(GameEngine::LUA_STATE, this);
  }

  const char *LuaBinded::getClassName()
  {
    return _className.c_str();
  }
} // namespace Aztec