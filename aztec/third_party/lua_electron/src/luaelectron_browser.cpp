#include "luaelectron_browser.h"
#include <tolua.h>
#include <iostream>

ElectronBrowser::ElectronBrowser(const char *command_line_args)
:ElectronWindow(command_line_args)
,m_luastate(NULL)
{
  AddListener("execute", [&](std::shared_ptr<Petunia::Message> message) {
    if (m_luastate) {
      lua_getglobal(m_luastate, "EventDispatcher");
      lua_getfield(m_luastate, -1, "Execute");
      tolua_pushusertype(m_luastate, this, "ElectronBrowser");
      tolua_pushstring(m_luastate, message->GetData()->c_str());

      if (lua_pcall(m_luastate, 2, 0, 0) != 0)
      {
        printf("LUA WebBrowser:Execute failed: %s - <%s [%d]>", lua_tostring(m_luastate, -1), __FILE__, __LINE__);
      }

      lua_pop(m_luastate, 1);
    }
  });
}

void ElectronBrowser::Execute(std::string& script)
{  
  SendMessage(std::make_shared<Petunia::Message>("execute", std::make_shared<std::string>(script)));
}

void ElectronBrowser::Execute(const char *script)
{
  SendMessage(std::make_shared<Petunia::Message>("execute", std::make_shared<std::string>(script)));
}

void ElectronBrowser::WindowExecute(const char *script)
{
  
  std::string window_script = "mainWindow.webContents.executeJavaScript(`"
    + std::string(script)
    + "`);";
  
     
  SendMessage(std::make_shared<Petunia::Message>("execute", std::make_shared<std::string>(window_script)));
}

void ElectronBrowser::SetFocus(bool value)
{
  if (value) {
    Execute("mainWindow.webContents.focus()");
  }
  else {
    Execute("mainWindow.webContents.blur()");
  }
}

void ElectronBrowser::SetLuaState(lua_State *state)
{
  m_luastate = state;
}

ElectronBrowser::~ElectronBrowser()
{
  SendMessage(std::make_shared<Petunia::Message>("destroy", std::make_shared<std::string>("")));
}
