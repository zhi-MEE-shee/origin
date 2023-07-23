cmake_minimum_required (VERSION 3.22.2)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED true)

project(Task3)
include_directories(Dynamic_lib_Farewell)

add_executable (Task3 main.cpp)

add_subdirectory(Dynamic_lib_Farewell)

target_link_libraries(Task3 Farewell_lib)