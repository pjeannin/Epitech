/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** create_end
*/

#include "../include/generator.h"

void create_end(map_t *map_struct, int *x, int *y)
{
    if (*x + 1 == map_struct->x - 1 && *y == map_struct->y - 1
    && map_struct->map[*y][*x + 1] == 'X') {
        ++(*x);
        map_struct->map[*y][*x] = 'o';
    } else if (*x == map_struct->x - 1 && *y + 1 == map_struct->y - 1
    && map_struct->map[*y + 1][*x] == 'X') {
        ++(*y);
        map_struct->map[*y][*x] = 'o';
    }
}