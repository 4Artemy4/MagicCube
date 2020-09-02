cmake_minimum_required(VERSION 3.16)
project(RubicksCube)

set(CMAKE_CXX_STANDARD 14)

add_executable(RubicksCube main.cpp "Cube/Side.cpp" "Cube/Side.h" Cube3.cpp Cube3.h Cube/Cube.cpp Cube/Cube.h)