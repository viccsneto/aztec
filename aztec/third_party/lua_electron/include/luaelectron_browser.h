#include "electron_window.h"
#include <lua.hpp>
class ElectronBrowser : public ElectronWindow
{
public:
  ElectronBrowser(const char *command_line_args = NULL);
  void Execute(std::string& script);
  void Execute(const char *script);
  void WindowExecute(const char *script);
  void SetLuaState(lua_State *state);
  void SetFocus(bool value);
  void Focus();
  void Blur();
  void SendMouseDown(int x, int y, const char *button, int click_count);
  void SendMouseMove(int x, int y);
  void SendMouseUp(int x, int y, const char *button);
  void SendMouseWheel(int deltaX, int deltaY);
  ~ElectronBrowser();
private:
  lua_State *m_luastate;
};