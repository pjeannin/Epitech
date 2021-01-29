#!/bin/bash

cd ..
gcc -c *.c
ar rc libmy.a *.o
mv libmy.a my/

