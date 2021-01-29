/*
** EPITECH PROJECT, 2020
** generator
** File description:
** no_more_moves
*/

#include "../include/generator.h"

int no_more_move_end(map_t *map_struct, int x, int y)
{
    if (((x - 1 >= 0 && map_struct->map[y][x - 1] == 'X')
    && ((y + 1 < map_struct->y && map_struct->map[y + 1][x - 1] == 'X')
    || y + 1 == map_struct->y)
    && ((y - 1 >= 0 && map_struct->map[y - 1][x - 1] == 'X') || y - 1 == -1)
    && (x - 2 == -1 || (x - 2 >= 0 && map_struct->map[y][x - 2] == 'X'))) == 0
    && ((x + 1 < map_struct->x && map_struct->map[y][x + 1] == 'X')
    && ((y + 1 < map_struct->y && map_struct->map[y + 1][x + 1] == 'X')
    || y + 1 == map_struct->y)
    && ((y - 1 >= 0 && map_struct->map[y - 1][x + 1] == 'X') || y - 1 == -1)
    && (x + 2 == map_struct->x + 1
    || (x + 2 < map_struct->x && map_struct->map[y][x + 2] == 'X'))) == 0)
        return (1);
    return (0);
}

int no_more_move(map_t *map_struct, int x, int y)
{
    if (((y - 1 >= 0 && map_struct->map[y - 1][x] == 'X')
    && ((x + 1 < map_struct->x && map_struct->map[y - 1][x + 1] == 'X')
    || x + 1 == map_struct->x)
    && ((x - 1 >= 0 && map_struct->map[y - 1][x - 1] == 'X') || x - 1 == -1)
    && (y - 2 == -1 || (y - 2 >= 0 && map_struct->map[y - 2][x] == 'X'))) == 0
    && ((y + 1 < map_struct->y && map_struct->map[y + 1][x] == 'X')
    && ((x + 1 < map_struct->x && map_struct->map[y + 1][x + 1] == 'X')
    || x + 1 == x)
    && ((x - 1 >= 0 && map_struct->map[y + 1][x - 1] == 'X') || x - 1 == -1)
    && (y + 2 == map_struct->y + 1
    || (y + 2 < map_struct->y && map_struct->map[y + 2][x] == 'X'))) == 0
    && no_more_move_end(map_struct, x, y))
        return (1);
    return (0);
}
