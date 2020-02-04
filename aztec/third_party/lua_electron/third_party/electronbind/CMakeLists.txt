cmake_minimum_required(VERSION 3.0)
project (electronbind CXX)
add_subdirectory (third_party)

add_library(electronbindlib
  "include/electron_bind.h"
  "include/electron_instance.h"
  "include/electron_osutils.h"
  "include/electron_window.h"
  "src/electron_bind.cpp"
  "src/electron_instance.cpp"
  "src/electron_osutils.cpp"
  "src/electron_window.cpp"
)


target_include_directories(electronbindlib
  PUBLIC
   include
)

target_link_libraries(electronbindlib 
  PUBLIC
    petunia
)

