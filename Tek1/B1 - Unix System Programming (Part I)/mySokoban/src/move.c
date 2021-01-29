/*
** EPITECH PROJECT, 2019
** move.c
** File description:
** my_sokoban
*/

#include "my_sokoban.h"

void move_left(map_t *map)
{
    if (map->map[map->posy][map->posx - 1] != '#'
    && map->map[map->posy][map->posx - 1] != 'X') {
        map->posx--;
        map->map[map->posy][map->posx] = 'P';
    } else if (map->map[map->posy][map->posx - 1] == 'X'
    && (map->map[map->posy][map->posx - 2] == ' ' 
    | map->map[map->posy][map->posx - 2] == 'O')) {
        map->posx--;
        map->map[map->posy][map->posx] = 'P';
        map->map[map->posy][map->posx - 1] = 'X';
    }
    if (map->initial_map[map->posy][map->posx + 1] == 'O'
    || map->initial_map[map->posy][map->posx + 1] == '#')
        map->map[map->posy][map->posx + 1] =
            map->initial_map[map->posy][map->posx + 1];
    else
        map->map[map->posy][map->posx + 1] = ' ';
}

void move_right(map_t *map)
{
    if (map->map[map->posy][map->posx + 1] != '#'
    && map->map[map->posy][map->posx + 1] != 'X') {
        map->posx++;
        map->map[map->posy][map->posx] = 'P';
    } else if (map->map[map->posy][map->posx + 1] == 'X'
    && (map->map[map->posy][map->posx + 2] == ' '
    || map->map[map->posy][map->posx + 2] == 'O')) {
        map->posx++;
        map->map[map->posy][map->posx] = 'P';
        map->map[map->posy][map->posx + 1] = 'X';
    }
    if (map->initial_map[map->posy][map->posx - 1] == 'O'
    || map->initial_map[map->posy][map->posx - 1] == '#')
        map->map[map->posy][map->posx - 1] =
            map->initial_map[map->posy][map->posx - 1];
    else
        map->map[map->posy][map->posx - 1] = ' ';
}

void move_up(map_t *map)
{
    if (map->map[map->posy - 1][map->posx] !=  '#'
    && map->map[map->posy - 1][map->posx] != 'X') {
        map->posy--;
        map->map[map->posy][map->posx] = 'P';
    } else if (map->map[map->posy - 1][map->posx] == 'X'
    && (map->map[map->posy - 2][map->posx] == ' '
    || map->map[map->posy - 2][map->posx] == 'O') ) {
        map->posy--;
        map->map[map->posy][map->posx] = 'P';
        map->map[map->posy - 1][map->posx] = 'X';
    }
    if (map->initial_map[map->posy + 1][map->posx] == 'O'
    || map->initial_map[map->posy + 1][map->posx] == '#')
        map->map[map->posy + 1][map->posx] =
            map->initial_map[map->posy + 1][map->posx];
    else
        map->map[map->posy + 1][map->posx] = ' ';
}

void move_down(map_t *map)
{
    if (map->map[map->posy + 1][map->posx] != '#'
    && map->map[map->posy + 1][map->posx] != 'X') {
        map->posy++;
        map->map[map->posy][map->posx] = 'P';

    } else if (map->map[map->posy + 1][map->posx] == 'X'
    && (map->map[map->posy + 2][map->posx] == ' '
    || map->map[map->posy + 2][map->posx] == 'O')) {
        map->posy++;
        map->map[map->posy][map->posx] = 'P';
        map->map[map->posy + 1][map->posx] = 'X';
    }
    if (map->initial_map[map->posy - 1][map->posx] == 'O'
    || map->initial_map[map->posy - 1][map->posx] == '#')
        map->map[map->posy - 1][map->posx] =
            map->initial_map[map->posy - 1][map->posx];
    else
        map->map[map->posy - 1][map->posx] = ' ';
}