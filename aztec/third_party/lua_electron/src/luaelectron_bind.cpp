/*
** Lua binding: luaelectron
*/

#include "tolua.h"

#ifndef __cplusplus
#include <stdlib.h>
#endif
#ifdef __cplusplus
 extern "C" int tolua_bnd_takeownership (lua_State* L); // from tolua_map.c
#else
 int tolua_bnd_takeownership (lua_State* L); /* from tolua_map.c */
#endif
#include <string.h>

/* Exported function */
TOLUA_API int tolua_luaelectron_open (lua_State* tolua_S);
LUALIB_API int luaopen_luaelectron (lua_State* tolua_S);

#include "luaelectron_browser.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_ElectronBrowser (lua_State* tolua_S)
{
 ElectronBrowser* self = (ElectronBrowser*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"ElectronBrowser");
 tolua_usertype(tolua_S,"ElectronWindow");
}

/* method: new of class  ElectronBrowser */
static int tolua_luaelectron_ElectronBrowser_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"ElectronBrowser",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,1,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* command_line_args = ((const char*)  tolua_tostring(tolua_S,2,NULL));
 {
  ElectronBrowser* tolua_ret = (ElectronBrowser*)  new ElectronBrowser(command_line_args);
  tolua_ret->SetLuaState(tolua_S);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"ElectronBrowser");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  ElectronBrowser */
static int tolua_luaelectron_ElectronBrowser_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ElectronBrowser",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ElectronBrowser* self = (ElectronBrowser*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: Execute of class  ElectronBrowser */
static int tolua_luaelectron_ElectronBrowser_Execute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"ElectronBrowser",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  ElectronBrowser* self = (ElectronBrowser*)  tolua_tousertype(tolua_S,1,0);
  const char* script = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Execute'",NULL);
#endif
 {
  self->Execute(script);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Execute'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_luaelectron (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"ElectronBrowser","ElectronBrowser","ElectronWindow",tolua_collect_ElectronBrowser);
#else
 tolua_cclass(tolua_S,"ElectronBrowser","ElectronBrowser","ElectronWindow",NULL);
#endif
 tolua_beginmodule(tolua_S,"ElectronBrowser");
 tolua_function(tolua_S,"new",tolua_luaelectron_ElectronBrowser_new00);
 tolua_function(tolua_S,"delete",tolua_luaelectron_ElectronBrowser_delete00);
 tolua_function(tolua_S,"Execute",tolua_luaelectron_ElectronBrowser_Execute00);
 tolua_endmodule(tolua_S);

 { /* begin embedded lua code */
 static unsigned char B[] = {
  10, 69,118,101,110,116, 68,105,115,112, 97,116, 99,104,101,
 114, 32, 61, 32,123,125, 10,102,117,110, 99,116,105,111,110,
  32, 69,118,101,110,116, 68,105,115,112, 97,116, 99,104,101,
 114, 46, 69,120,101, 99,117,116,101, 40,115,101,110,100,101,
 114, 44, 32,115, 99,114,105,112,116, 41, 10,115, 99,114,105,
 112,116, 95,102,117,110, 99,116,105,111,110, 32, 61, 32,108,
 111, 97,100, 40, 34,114,101,116,117,114,110, 32,102,117,110,
  99,116,105,111,110, 40,115,101,110,100,101,114, 44, 32,115,
  99,114,105,112,116, 41, 32, 34, 46, 46,115, 99,114,105,112,
 116, 46, 46, 34, 32,101,110,100, 34, 41, 10,120,112, 99, 97,
 108,108, 40,102,117,110, 99,116,105,111,110, 40, 41, 32,115,
  99,114,105,112,116, 95,102,117,110, 99,116,105,111,110, 40,
  41, 40,115,101,110,100,101,114, 44, 32,115, 99,114,105,112,
 116, 41, 32,101,110,100, 44, 32,100,101, 98,117,103, 46,116,
 114, 97, 99,101, 98, 97, 99,107, 41, 59, 10,101,110,100,32
 };
 if (luaL_loadbuffer(tolua_S,(char*)B,sizeof(B),"tolua: embedded Lua code") == LUA_OK)
 lua_pcall(tolua_S,0,LUA_MULTRET,0);
 } /* end of embedded lua code */

 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_luaelectron_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_luaelectron);
 lua_pushstring(tolua_S, "luaelectron");
 lua_call(tolua_S, 1, 0);
 return 1;
}
