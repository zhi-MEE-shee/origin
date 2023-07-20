cmake_minimum_required (VERSION 3.22.2)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED true)

project(Figures_lib)

set(FIGURES_LIB EquilateralTriangle.cpp Figure.cpp Figure.h IsoscelesTriangle.cpp Parallelogram.cpp Parallelogram.h 
Quadrangle.cpp Quadrangle.h Rectangle_.cpp Rectangle_.h Rhombus.cpp RightTriangle.cpp Square.cpp Triangle.cpp Triangle.h)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library (Figures_library SHARED ${FIGURES_LIB})
