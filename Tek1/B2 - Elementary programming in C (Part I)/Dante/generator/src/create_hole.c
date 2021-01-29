/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** create_hole
*/

#include "../include/generator.h"

void create_holes(map_t *map_struct)
{
    srand(time(NULL));
    for (int i = 0; i < map_struct->y; ++i)
        for (int j = 0; j < map_struct->x; ++j) {
            if ((rand() % 5) == 0)
                map_struct->map[i][j] = '*';
        }
}