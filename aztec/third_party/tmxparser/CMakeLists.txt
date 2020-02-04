cmake_minimum_required(VERSION 2.8)
project(tmxparser)
add_subdirectory (third_party)

set (TINYXML2_INCLUDE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/third_party/tinyxml2/)
set(ZLIB_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/zlib/)
set(TINYXML2_LIBRARIES tinyxml2)
set(ZLIB_LIBRARIES zlibstatic)
set(ZLIB_LIBRARY zlibstatic)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake ${CMAKE_MODULE_PATH})

set(VERSION_MAJOR 2)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
set(CMAKE_CXX_STANDARD 11)

message("Configuring tmxparser version ${VERSION}")
configure_file(
  "${PROJECT_SOURCE_DIR}/src/Tmx.h.in"
  "${PROJECT_BINARY_DIR}/Tmx.h"
  )

option(USE_MINIZ "Use miniz.c instead of zlib" OFF)

if (USE_MINIZ)
    add_definitions(-DUSE_MINIZ)
endif (USE_MINIZ)

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${PROJECT_SOURCE_DIR}/src/*.h
                          ${PROJECT_BINARY_DIR}/Tmx.h)

if (USE_MINIZ)
    set(SOURCES ${SOURCES} ${PROJECT_SOURCE_DIR}/src/miniz.c)
endif (USE_MINIZ)

find_package(TinyXML2)

if (NOT USE_MINIZ)
    find_package(ZLIB)
endif (NOT USE_MINIZ)

set(LIB_CFLAGS "-std=c++11 -pedantic -Wall")

if (NOT USE_MINIZ)
    list(APPEND ${LIB_CFLAGS} "-Werror")
endif (NOT USE_MINIZ)

set(EXAMPLE_CFLAGS "-std=c++11 -pedantic -Werror -Wall -g")
#include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(tmxparser_static ${SOURCES} ${HEADERS})
#set_target_properties(tmxparser_static PROPERTIES
#  OUTPUT_NAME tmxparser
#  COMPILE_FLAGS ${LIB_CFLAGS})

#add_library(tmxparser SHARED ${SOURCES} ${HEADERS})
set_target_properties(tmxparser_static PROPERTIES
  SOVERSION ${VERSION_MAJOR}
  VERSION ${VERSION}
  COMPILE_FLAGS ${LIB_CFLAGS})

target_link_libraries(tmxparser_static ${TINYXML2_LIBRARIES})
include_directories(${TINYXML2_INCLUDE_DIR})

if (NOT USE_MINIZ)
    target_link_libraries(tmxparser_static ${ZLIB_LIBRARIES})
    include_directories(${ZLIB_INCLUDE_DIRS})
endif (NOT USE_MINIZ)


#install(FILES ${HEADERS} DESTINATION include/tmxparser)
install(TARGETS tmxparser_static DESTINATION lib)

configure_file(src/tmxparser.pc.in tmxparser.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/tmxparser.pc DESTINATION lib/pkgconfig)

# Build documentation
#find_package(Doxygen)
#
#if(DOXYGEN_FOUND)
#    configure_file(${PROJECT_SOURCE_DIR}/Doxyfile.in ${PROJECT_BINARY_DIR}/doc/Doxyfile @ONLY)
#    add_custom_target(doc ALL ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/doc/Doxyfile  COMMENT "Generating API documentation with Doxygen" VERBATIM)
#endif(DOXYGEN_FOUND)
