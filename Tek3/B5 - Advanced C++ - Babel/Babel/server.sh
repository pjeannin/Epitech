#!/bin/bash

mkdir build
cd build
conan install .. --build=missing
cmake ..
make
sqlite3 bin/babel.db < ../babel_schema.sql
cd bin/
./babel_server

