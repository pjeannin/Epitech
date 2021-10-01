CMAKE_MINIMUM_REQUIRED(VERSION 3.19)
project(Trade)
include_directories(include)
add_executable(trade src/Trade.cpp include/Trade.hpp src/Main.cpp include/Settings.hpp include/Candle.hpp)