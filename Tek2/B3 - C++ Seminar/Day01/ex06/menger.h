/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD01-pierre.jeannin
** File description:
** menger
*/

#ifndef MENGER_H_
#define MENGER_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "drawing.h"

unsigned int **menger(point_t point, double size, int level,
unsigned int **img);
int error_handling(int argc, char **argv);

#endif /* !MENGER_H_ */