cmake_minimum_required(VERSION 3.16)
project(RubicksCube)

set(CMAKE_CXX_STANDARD 14)

add_executable(RubicksCube main.cpp "Abstract Cube/AbstractCube.cpp" "Abstract Cube/AbstractCube.h" "Abstract Cube/Side.cpp" "Abstract Cube/Side.h" Cube3.cpp Cube3.h Consol/ConsolOut.cpp Consol/ConsolOut.h)