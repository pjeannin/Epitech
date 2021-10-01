cmake_minimum_required(VERSION 3.17)
project(raylib-cpp)

include(Findraylib.cmake)

add_definitions( "-g3 -O3" )

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
add_library(raylib-cpp STATIC
            src/audioDevice/AudioDevice.cpp
            src/boundingBox/BoundingBox.cpp
            src/camera/Camera.cpp
            src/color/Color.cpp
            src/font/Font.cpp
            src/functions/Functions.cpp
            src/image/Image.cpp
            src/matrix/Matrix.cpp
            src/mesh/Mesh.cpp
            src/model/Model.cpp
            src/modelAnimation/ModeAnimation.cpp
            src/mouse/Mouse.cpp
            src/music/Music.cpp
            src/ray/Ray.cpp
            src/rayCollision/RayCollision.cpp
            src/rectangle/Rectangle.cpp
            src/renderTexture/RenderTexture.cpp
            src/shader/Shader.cpp
            src/sound/Sound.cpp
            src/text/Text.cpp
            src/texture/Texture.cpp
            src/vector/Vector.cpp
            src/window/Window.cpp
            src/text/Text.cpp
            src/utils/Utils.cpp
            )

target_link_libraries(raylib-cpp PUBLIC raylib)

install(TARGETS raylib-cpp DESTINATION .)
install(FILES raylib-cpp.hpp DESTINATION .)
