# CMake entry point
cmake_minimum_required (VERSION 3.0)
project (Lua)

add_library(lualib
  src/lapi.c 
  src/lauxlib.c 
  src/lbaselib.c 
  src/lbitlib.c 
  src/lcode.c 
  src/lcorolib.c 
  src/lctype.c 
  src/ldblib.c 
  src/ldebug.c 
  src/ldo.c 
  src/ldump.c 
  src/lfunc.c 
  src/lgc.c 
  src/linit.c 
  src/liolib.c 
  src/llex.c 
  src/lmathlib.c 
  src/lmem.c 
  src/loadlib.c 
  src/lobject.c 
  src/lopcodes.c 
  src/loslib.c 
  src/lparser.c 
  src/lstate.c 
  src/lstring.c 
  src/lstrlib.c 
  src/ltable.c 
  src/ltablib.c 
  src/ltm.c 
  src/lundump.c 
  src/lutf8lib.c 
  src/lvm.c 
  src/lzio.c 
)

add_library(tolualib 
  src/tolua_event.c
  src/tolua_is.c
  src/tolua_map.c 
  src/tolua_push.c
  src/tolua_to.c
)

target_include_directories(lualib
  PUBLIC
    include	
  PRIVATE
    src
)

target_include_directories(tolualib
PUBLIC
  include	
PRIVATE
  src
)

add_executable(lua src/lua.c)
add_executable(luac src/luac.c)
add_executable(tolua src/tolua.c src/toluabind.c)

target_link_libraries(tolualib PRIVATE lualib)
target_link_libraries(tolua PRIVATE tolualib)
target_link_libraries(lua PRIVATE lualib)
target_link_libraries(luac PRIVATE lualib)
