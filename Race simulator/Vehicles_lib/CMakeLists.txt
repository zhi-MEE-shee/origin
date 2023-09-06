cmake_minimum_required (VERSION 3.22.2)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED true)

project(Vehicles_lib)

set(VEHICLES_LIB air_vehicles.cpp air_vehicles.h boots.cpp broom.cpp camel.cpp 
carpet.cpp centaur.cpp eagle.cpp earth_vehicles.cpp earth_vehicles.h speed_camel.cpp vehicles.cpp vehicles.h)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library (Vehicles_library SHARED ${VEHICLES_LIB})
