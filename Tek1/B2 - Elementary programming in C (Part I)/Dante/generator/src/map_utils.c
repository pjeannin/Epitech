/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** map_utils
*/

#include "../include/generator.h"

char **free_map(char **map, int i)
{
    for (int j = 0; j < i; ++j)
        free(map[j]);
    free(map);
    return ((char **)-1);
}

char **create_map(int x, int y)
{
    char **map = malloc(sizeof(char *) * y + 1);

    if (map == NULL)
        return ((char **)-1);
    for (int i = 0; i < y; ++i) {
        map[i] = malloc(sizeof(char) * x + 1);
        if (map[i] == NULL)
            return (free_map(map, i));
        for (int j = 0; j < x; ++j)
            map[i][j] = 'X';
        map[i][x] = '\0';
    }
    return (map);
}