/*
** EPITECH PROJECT, 2020
** generator
** File description:
** moves
*/

#include "../include/generator.h"

void move_right(map_t *map_struct, int *x, int *y)
{
    if ((*x + 1 < map_struct->x && map_struct->map[*y][*x + 1] == 'X')
    && ((*y + 1 < map_struct->y && map_struct->map[*y + 1][*x + 1] == 'X')
    || *y + 1 == map_struct->y)
    && ((*y - 1 >= 0 && map_struct->map[*y - 1][*x + 1] == 'X') || *y - 1 == -1)
    && (*x + 2 == map_struct->x
    || (*x + 2 < map_struct->x && map_struct->map[*y][*x + 2] == 'X'))) {
        ++*x;
        map_struct->map[*y][*x] = 'o';
    }
}

void move_left(map_t *map_struct, int *x, int *y)
{
    if ((*x - 1 >= 0 && map_struct->map[*y][*x - 1] == 'X')
    && ((*y + 1 < map_struct->y && map_struct->map[*y + 1][*x - 1] == 'X')
    || *y + 1 == map_struct->y)
    && ((*y - 1 >= 0 && map_struct->map[*y - 1][*x - 1] == 'X') || *y - 1 == -1)
    && (*x - 2 == -1 || (*x - 2 >= 0 && map_struct->map[*y][*x - 2] == 'X'))) {
        --(*x);
        map_struct->map[*y][*x] = 'o';
    }
}

void move_down(map_t *map_struct, int *x, int *y)
{
    if ((*y + 1 < map_struct->y && map_struct->map[*y + 1][*x] == 'X')
    && ((*x + 1 < map_struct->x && map_struct->map[*y + 1][*x + 1] == 'X')
    || *x + 1 == map_struct->x)
    && ((*x - 1 >= 0 && map_struct->map[*y + 1][*x - 1] == 'X') || *x - 1 == -1)
    && (*y + 2 == map_struct->y
    || (*y + 2 < map_struct->y && map_struct->map[*y + 2][*x] == 'X'))) {
        ++(*y);
        map_struct->map[*y][*x] = 'o';
    }
}

void move_up(map_t *map_struct, int *x, int *y)
{
    if ((*y - 1 >= 0 && map_struct->map[*y - 1][*x] == 'X')
    && ((*x + 1 < map_struct->x && map_struct->map[*y - 1][*x + 1] == 'X')
    || *x + 1 == map_struct->x)
    && ((*x - 1 >= 0 && map_struct->map[*y - 1][*x - 1] == 'X') || *x - 1 == -1)
    && (*y - 2 == -1 || (*y - 2 >= 0 && map_struct->map[*y - 2][*x] == 'X'))) {
        --(*y);
        map_struct->map[*y][*x] = 'o';
    }
}