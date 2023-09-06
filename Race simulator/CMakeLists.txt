cmake_minimum_required (VERSION 3.22.2)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED true)

project(Race_simulator)
include_directories(Vehicles_lib)

add_executable (Race main.cpp)
add_subdirectory(Vehicles_lib)

target_link_libraries(Race Vehicles_library)