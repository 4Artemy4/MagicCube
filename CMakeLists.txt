cmake_minimum_required(VERSION 3.16)
project(RubicksCube)

set(CMAKE_CXX_STANDARD 14)

add_executable(RubicksCube main.cpp "Cube/Side.cpp" "Cube/Side.h" Cube3.cpp Cube3.h Cube/Cube.cpp Cube/Cube.h GUI/Drawer.cpp GUI/Drawer.h GUI/Button.cpp GUI/Button.h Tests/tests.cpp)

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

target_link_libraries(RubicksCube sfml-graphics sfml-audio)