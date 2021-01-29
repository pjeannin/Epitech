/*
** EPITECH PROJECT, 2019
** game_bonus.c
** File description:
** my_sokoban bonus
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my_sokoban.h"

map_t *init_game_bonus(char *filepath)
{
    map_t *map;

    map = init_map(filepath);
    return (map);
}

void end_game_bonus(map_t *map)
{
    for (int i = 0; i < map->nbr_line; ++i) {
        free(map->map[i]);
        free(map->initial_map[i]);
    }
    free(map->map);
    free(map->initial_map);
    free(map);
}

char *char_from_int(int nbr)
{
    int cpy = nbr;
    int len = 0;
    int i = 0;
    char *n;

    while (cpy > 0) {
        ++len;
        cpy /= 10;
    }
    if (len == 0)
        return("0");
    n = malloc(sizeof(char) * len);
    while (nbr > 0) {
        n[i] = (nbr % 10) | 48;
        ++i;
        nbr /= 10;
    }
    n[i] = '\0';
    return (n);
}