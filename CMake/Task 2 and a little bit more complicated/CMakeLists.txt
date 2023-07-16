cmake_minimum_required (VERSION 3.22.2)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED true)

project(Task2)

add_executable (Task2 main.cpp EquilateralTriangle.cpp Figure.cpp Figure.h IsoscelesTriangle.cpp Parallelogram.cpp Parallelogram.h 
Quadrangle.cpp Quadrangle.h Rectangle_.cpp Rectangle_.h Rhombus.cpp RightTriangle.cpp Square.cpp Triangle.cpp Triangle.h)
