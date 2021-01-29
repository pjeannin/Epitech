/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** free_construction_map
*/

#include "my_defender.h"

void free_construction_map(char **map)
{
    for (int i = 0; i < 9; ++i)
        free(map[i]);
    free(map);
}