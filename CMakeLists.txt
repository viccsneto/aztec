cmake_minimum_required (VERSION 3.0)

project (AZTEC)
add_subdirectory(aztec)
include_directories(
  aztec/include
  aztec/third_party/lua/include
  aztec/third_party/glm/
  aztec/third_party/glew/include/
  aztec/third_party/Box2D/
  aztec/third_party/tmxparser/src/  
)

add_definitions(
  -DTW_STATIC
  -DGLEW_STATIC
  -D_CRT_SECURE_NO_WARNINGS
  -DSFML_STATIC
)

set_target_properties (azteclib PROPERTIES
    FOLDER aztec_lib
)

add_executable(aztecapp app/main.cpp)
target_link_libraries(aztecapp azteclib)

set_property (GLOBAL PROPERTY USE_FOLDERS ON)

SET(CMAKE_DEFAULT_STARTUP_PROJECT aztecapp)