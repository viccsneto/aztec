# CMake entry point
cmake_minimum_required (VERSION 3.0)
project (sqlite3)


set(SQLITE3_SRCS
	src/sqlite3.c
  src/CppSQLite3.cpp	
)
set(SQLITE3_HDRS
	include/sqlite3/sqlite3.h
  include/sqlite3/CppSQLite3.h	
)

include_directories(
  include/
)

add_library(sqlite3 STATIC
		${SQLITE3_HDRS}
    ${SQLITE3_SRCS}
)