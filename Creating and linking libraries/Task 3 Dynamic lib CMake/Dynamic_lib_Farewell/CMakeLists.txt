cmake_minimum_required (VERSION 3.22.2)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED true)

project(Task3_lib)

set(FAREWELL_DLL Farewell.cpp Farewell.h)

add_library (Farewell_lib SHARED ${FAREWELL_DLL}) 
target_compile_definitions(Farewell_lib PRIVATE DYNAMIC_LIB_FAREWELL)

