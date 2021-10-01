cmake_minimum_required(VERSION 3.17)
project(bomberman)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_definitions( "-g3 -O3" )

add_subdirectory(raylib-cpp)

link_directories(raylib-cpp/raylib)

include_directories(raylib-cpp)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")

add_executable(bomberman ${SOURCES} src/components/boat/IBoatController.hpp src/components/button/Button.cpp src/components/image/Image.c++ src/components/image/Image.hpp src/components/animation/Animation.cpp src/components/animation/Animation.hpp src/components/button/Button.hpp src/components/text/Text.cpp src/components/text/Text.hpp src/components/transition/fade/Fade.cpp src/components/transition/fade/Fade.hpp src/scene/game/PauseMenu.cpp src/scene/IScene.cpp)

target_link_libraries(bomberman PUBLIC raylib-cpp)

target_include_directories(bomberman PUBLIC
							${PUBLIC_BINARY_DIR}
							${PUBLIC_BINARY_DIR}/raylib-cpp
							${PUBLIC_BINARY_DIR}/src)

install(TARGETS bomberman DESTINATION ..\\..\\..\\.)
