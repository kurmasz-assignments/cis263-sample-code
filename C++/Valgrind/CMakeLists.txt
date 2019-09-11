cmake_minimum_required(VERSION 3.14)
project(Valgrind)

set(CMAKE_CXX_STANDARD 17)

add_executable(valgrindMemoryDemo src/valgrindMemoryDemo.cpp)
add_executable(valgrindBoundsCheck src/valgrindBoundsCheck.cpp)