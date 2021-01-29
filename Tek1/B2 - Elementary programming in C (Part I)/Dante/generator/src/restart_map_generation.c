/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** restart_map_generation
*/

#include "../include/generator.h"

void restart_map_generation(map_t *map_struct, int *x, int *y)
{
    *x = 0;
    *y = 0;
    free_map(map_struct->map, map_struct->y);
    map_struct->map = create_map(map_struct->x, map_struct->y);
    map_struct->map[0][0] = 'o';
}