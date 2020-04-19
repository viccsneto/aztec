cmake_minimum_required (VERSION 3.0)

project(azteclib)
find_package(OpenGL)

add_subdirectory (third_party)

include_directories(
  include/
  third_party/glew/include/
  third_party/glfw/include/GLFW/	
  third_party/glm/
  third_party/lua/include/
  third_party/SOIL/include/
  third_party/SFML/include/
  third_party/Box2D/
  third_party/sqlite3/include/
  third_party/tmxparser/src/
)

set(AZTEC_SOURCE
  "src/Animation.cpp"
  "src/AutoSensor.cpp"
  "src/Bitwise.cpp"
  "src/Camera.cpp"
  "src/Config.cpp"
  "src/ContactFilter.cpp"
  "src/ContactSolver.cpp"
  "src/DebugDraw.cpp"
  "src/EventDispatcher.cpp"
  "src/EventTypes.cpp"
  "src/Font.cpp"
  "src/Frame.cpp"
  "src/Keyboard.cpp"
  "src/GameCanvas.cpp"
  "src/GameEngine.cpp"
  "src/GameObject.cpp"
  "src/GameStateController.cpp"
  "src/PropertyList.cpp"
  "src/PointList2D.cpp"
  "src/PropertyManager.cpp"
  "src/GameObjectList.cpp"
  "src/Aztec_Lua_Bind.cpp"
  "src/LuaBinded.cpp"
  "src/Mouse.cpp"
  "src/Music.cpp"
  "src/Plane.cpp"
  "src/Rectangle.cpp"
  "src/ResourceManager.cpp"
  "src/Sensor.cpp"
  "src/Shader.cpp"
  "src/Shape.cpp"
  "src/Sound.cpp"
  "src/Sprite.cpp"
  "src/SpriteSensor.cpp"
  "src/Text.cpp"
  "src/Texture.cpp"
  "src/Transform.cpp"
  "src/Vector2.cpp"
  "src/VertexArrayObject.cpp"
  "src/VertexBufferObject.cpp"
  "src/WebBrowser.cpp"
  "src/json.hpp"
)

set(AZTEC_INCLUDE
  "include/Animation.h"
  "include/AutoSensor.h"
  "include/Bitwise.h"
  "include/Camera.h"
  "include/Config.h"
  "include/ContactFilter.h"
  "include/ContactSolver.h"
  "include/DebugDraw.h"
  "include/EventDispatcher.h"
  "include/EventTypes.h"
  "include/Font.h"
  "include/Frame.h"
  "include/Keyboard.h"
  "include/GameCanvas.h"
  "include/GameEngine.h"
  "include/GameObject.h"
  "include/GameStateController.h"
  "include/PropertyList.h"
  "include/PropertyManager.h"
  "include/PointList2D.h"
  "include/GameObjectList.h"
  "include/Aztec_Lua_Bind.h"
  "include/LuaBinded.h"
  "include/Mouse.h"
  "include/Music.h"
  "include/Plane.h"
  "include/Rectangle.h"
  "include/ResourceManager.h"
  "include/Sensor.h"
  "include/Shader.h"
  "include/Shape.h"
  "include/Sound.h"
  "include/Sprite.h"
  "include/SpriteSensor.h"
  "include/Text.h"
  "include/Texture.h"
  "include/Transform.h"  
  "include/Vector2.h"
  "include/VertexArrayObject.h"
  "include/VertexBufferObject.h"
  "include/WebBrowser.h"
)



add_definitions(
	-DTW_STATIC
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
  -DSFML_STATIC
)

add_library(azteclib STATIC
	${AZTEC_SOURCE}
	${AZTEC_INCLUDE}
)

set(SFML_LIBRARIES 
	sfml-audio
	sfml-graphics
	sfml-main
	sfml-network
	sfml-system
	sfml-window
)
	


message(WARNING ${SFML_LIBRARIES})

target_link_libraries(azteclib 
  ${OPENGL_LIBRARY}
  Box2D   
  glew 
  glfw 
  luaelectron_lib
  ${SFML_LIBRARIES}
  sqlite3
  tmxparser_static
)

#SOURCE_GROUP(TREE third_party PREFIX third_party/ FILES **)