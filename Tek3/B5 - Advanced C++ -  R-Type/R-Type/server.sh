#!/bin/bash

mkdir build
cd build
conan install .. --build=missing -s cppstd=gnu20
cmake ..
make
cd bin/
./rtype_server

