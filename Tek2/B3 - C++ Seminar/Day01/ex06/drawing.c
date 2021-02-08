/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD01-pierre.jeannin
** File description:
** drawing
*/

#include <stdlib.h>
#include "bitmap.h"
#include "drawing.h"

void draw_square(uint32_t **img, point_t point, size_t size,
uint32_t color)
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            img[(int)point.x + i][(int)point.y + j] = color;
}