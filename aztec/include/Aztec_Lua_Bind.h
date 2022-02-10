#pragma once
/*
** Lua binding: lua_bind
** Generated automatically by tolua 5.1.4 on 06/07/12 04:09:01.
*/
//#define TOLUA_RELEASE
#include <tolua.h>
/* Exported function */
using namespace Aztec;

/**
* Provides more info in the error messages of the binding
*/


#ifndef tolua_hacks
#define tolua_hacks
//OPTIMIZES INT TO BOOLEAN CONVERSION
#define tolua_toboolean(state, narg, def) (tolua_toboolean(state, narg, def) != 0)

//NECESSARY TO CONVERT THE LINE NUMBER TO STRING
#define __NUMBER_TO_STRING__(x) __NUMBER_TO_STRING__2__(x)
#define __NUMBER_TO_STRING__2__(x) #x

//DISPLAY MORE DEBUG INFO
#if 0
#define __Aztec__MORE_INFO__                                                                                                                                                       \
  "\nfile: "__FILE__                                                                                                                                                               \
  "\nfunction"__FUNCTION__                                                                                                                                                         \
  " ("__NUMBER_TO_STRING__(__LINE__) ")\n"
#define tolua_error(A, B, C) tolua_error(A, B __Aztec__MORE_INFO__, C)
#endif
#endif

/**
* Provides more info in the error messages of the binding
*/


TOLUA_API int  tolua_Aztec_Lua_Bind(lua_State *tolua_S);
LUALIB_API int luaopen_Aztec_Lua_Bind(lua_State *tolua_S);