cmake_minimum_required (VERSION 3.0)

if(MSVC AND NOT "${MSVC_VERSION}" LESS 1400)
	add_definitions( "/MP" )
endif()
find_package(OpenGL)

add_definitions(
	-DTW_STATIC
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
	-DSFML_STATIC
#	-DSFML_ROOT ${CMAKE_CURRENT_LIST_DIR}/SFML
)

### GLFW ###

add_subdirectory (glfw)

include_directories(
  glew/include/
  glfw/include/GLFW/	
  glm/
  lua_electron/include/
  SFML/include/
  Box2D/
  sqlite3/include/  
)


if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set(OPENGL_LIBRARY
	${OPENGL_LIBRARY}
	-lGL -lGLU -lXrandr -lXext -lX11 -lrt
	${CMAKE_DL_LIBS}
	${GLFW_LIBRARIES}
)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
set(OPENGL_LIBRARY
	${OPENGL_LIBRARY}
	${CMAKE_DL_LIBS}
	${GLFW_LIBRARIES}
)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

### GLEW ###

add_subdirectory(glew)

### Box2D ###
add_subdirectory (Box2D)

### Lua ###
add_subdirectory (lua_electron)


### SFML ###
add_subdirectory (SFML)

### SQLITE3 ###
add_subdirectory (sqlite3)

### TMXPARSER ###
add_subdirectory (tmxparser)
#set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/SFML/cmake/Modules)
##include(FindPkgConfig)
#set(SFML_DIR ${CMAKE_CURRENT_LIST_DIR}/SFML/cmake)
#find_package(SFML REQUIRED system window graphics network audio)