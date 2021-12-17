cmake_minimum_required(VERSION 3.19)

project(Babel LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -fPIC -g")
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

include(${PROJECT_SOURCE_DIR}/build/conanbuildinfo.cmake)
include(build/conan_paths.cmake)
conan_basic_setup(KEEP_RPATHS)
conan_basic_setup(KEEP_RPATHS)

file(GLOB_RECURSE SRC_CLIENT ${PROJECT_SOURCE_DIR}/client/*)
file(GLOB_RECURSE SRC_SERVER ${PROJECT_SOURCE_DIR}/server/*)

file(GLOB_RECURSE SRC_COMMON ${PROJECT_SOURCE_DIR}/shared_files/*)

add_executable(babel_client ${SRC_CLIENT} ${SRC_COMMON})
add_executable(babel_server ${SRC_SERVER} ${SRC_COMMON})

target_include_directories(babel_server PUBLIC shared_include)
target_include_directories(babel_client PUBLIC shared_include)
target_include_directories(babel_server PUBLIC shared_files)
target_include_directories(babel_client PUBLIC shared_files)

find_package(Qt5 COMPONENTS Widgets)

conan_target_link_libraries(babel_client PRIVATE CONAN_PKG::PORTAUDIO)
conan_target_link_libraries(babel_client PRIVATE CONAN_PKG::OPUS)
conan_target_link_libraries(babel_client PRIVATE CONAN_PKG::QT)

conan_target_link_libraries(babel_server PRIVATE CONAN_PKG::ASIO)
