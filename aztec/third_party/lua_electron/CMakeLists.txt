cmake_minimum_required(VERSION 3.0)

project(LuaElectron)

add_subdirectory (third_party)

add_library(luaelectron_lib 
  "include/luaelectron_bind.h"
  "include/luaelectron_browser.h"  
  "src/luaelectron_bind.cpp"
  "src/luaelectron_browser.cpp"
)

add_executable(luaelectron_app 
  "src/luaelectron.cpp"
  
  
)

target_include_directories(luaelectron_lib
  PUBLIC
   include
)

target_include_directories(luaelectron_app
  PRIVATE
   include
)
target_link_libraries(luaelectron_lib
  PUBLIC
  electronbindlib
  lualib 
  tolualib 
)  
target_link_libraries(luaelectron_app 
  PRIVATE  
  luaelectron_lib
)

set (CMAKE_CXX_STANDARD 11)

target_compile_definitions(luaelectron_app 	
  PRIVATE
  -D_CRT_SECURE_NO_WARNINGS
)