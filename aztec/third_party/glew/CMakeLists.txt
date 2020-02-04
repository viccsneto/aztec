# CMake entry point
cmake_minimum_required (VERSION 3.0)

project (glew)

add_definitions(
	-DTW_STATIC
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

find_package(OpenGL)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

add_library(glew STATIC
  src/glew.c      
  include/GL/eglew.h  
  include/GL/glew.h  
  include/GL/wglew.h 
  include/GL/glxew.h
)

target_link_libraries(glew ${OPENGL_LIBRARY})


set_target_properties(glew PROPERTIES LINKER_LANGUAGE CXX)
