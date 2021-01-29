/*
** EPITECH PROJECT, 2019
** set_st_square.c
** File description:
** bsq
*/

#include "bsq.h"

void set_struct_to(struct square *prev, int lenght, int line, int col)
{
    prev->lenght = lenght;
    prev->width = lenght;
    prev->x = line;
    prev->y = col;
}