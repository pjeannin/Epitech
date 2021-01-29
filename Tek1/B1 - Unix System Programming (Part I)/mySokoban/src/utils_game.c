/*
** EPITECH PROJECT, 2019
** utils_gale.c
** File description:
** my_sokoban
*/

#include <ncurses.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_sokoban.h"

char chek_nomove(map_t *map)
{
    for (int i = 1; i < map->nbr_line - 1; ++i)
        for (int j = 1; map->map[i][j + 1] != '\n'; ++j)
            if (map->map[i][j] == 'X' && ((map->map[i + 1][j]  == '#'
            && map->map[i][j + 1] == '#') || (map->map[i + 1][j] == '#'
            && map->map[i][j - 1] == '#') || (map->map[i - 1][j] == '#'
            && map->map[i][j - 1] == '#') || (map->map[i - 1][j] == '#'
            && map->map[i][j + 1] == '#')))
                return (' ');
    return ('f');
}

void restart(map_t *map)
{
    for (int i = 0; i < map->nbr_line; ++i)
        for (int j = 0; map->initial_map[i][j] != '\n'; ++j)
            map->map[i][j] = map->initial_map[i][j];
    map->posx = map->init_posx;
    map->posy = map->init_posy;
}