#include "electron_window.h"
#include <lua.hpp>
class ElectronBrowser : public ElectronWindow
{
public:
  ElectronBrowser(const char *command_line_args = NULL);
  void Execute(const char *script);
  void SetLuaState(lua_State *state);
  ~ElectronBrowser();
private:
  lua_State *m_luastate;
};