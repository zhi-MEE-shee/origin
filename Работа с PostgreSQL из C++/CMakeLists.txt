cmake_minimum_required (VERSION 3.20)

set(PostgreSQL_ADDITIONAL_VERSION "16")

project(Task5)

add_subdirectory("G:\\libpqxx-7.8.1" libpqxx_build)

add_executable(Task5 main.cpp)

target_compile_features(Task5 PRIVATE cxx_std_17)

target_link_libraries(Task5 pqxx)