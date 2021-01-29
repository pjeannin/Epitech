/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** back_step
*/

#include "../include/generator.h"

void back_step_end(map_t *map_struct, int *x, int *y)
{
    if (*y + 1 < map_struct->y && map_struct->map[*y + 1][*x] == 'x')
        ++(*y);
    else if (*y - 1 >= 0 && map_struct->map[*y - 1][*x] == 'x')
        --(*y);
}

void back_step_bis_bis(map_t *map_struct, int *x, int *y)
{
    if (*x + 1 < map_struct->x && map_struct->map[*y][*x + 1] == 'x')
        ++(*x);
    else if (*x - 1 >= 0 && map_struct->map[*y][*x - 1] == 'x')
        --(*x);
    else
        back_step_end(map_struct, x, y);
}

void back_step_bis(map_t *map_struct, int *x, int *y)
{
    if (*y + 1 < map_struct->y && map_struct->map[*y + 1][*x] == 'o')
        ++(*y);
    else if (*y - 1 >= 0 && map_struct->map[*y - 1][*x] == 'o')
        --(*y);
    else
        back_step_bis_bis(map_struct, x, y);
}

void back_step(map_t *map_struct, int *x, int *y)
{
    map_struct->map[*y][*x] = 'x';
    if (*x + 1 < map_struct->x && map_struct->map[*y][*x + 1] == 'o')
        ++(*x);
    else if (*x - 1 >= 0 && map_struct->map[*y][*x - 1] == 'o')
        --(*x);
    else
        back_step_bis(map_struct, x, y);
}