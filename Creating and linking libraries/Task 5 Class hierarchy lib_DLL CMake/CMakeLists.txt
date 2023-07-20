cmake_minimum_required (VERSION 3.22.2)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED true)

project(Task5)
include_directories(Figures_lib)

add_executable (Figures main.cpp)
add_subdirectory(Figures_lib)

target_link_libraries(Figures Figures_library)