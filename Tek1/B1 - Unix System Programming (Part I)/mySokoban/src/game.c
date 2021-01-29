/*
** EPITECH PROJECT, 2019
** game.c
** File description:
** my_sokoban
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my_sokoban.h"

map_t *init_game(char *filepath)
{
    map_t *map;

    initscr();
    keypad(stdscr, true);
    map = init_map(filepath);
    return (map);
}

void end_game(map_t *map)
{
    endwin();
    for (int i = 0; i < map->nbr_line; ++i) {
        free(map->map[i]);
        free(map->initial_map[i]);
    }
    free(map->map);
    free(map->initial_map);
    free(map);
}

void game(int *c, map_t *map, int *end, int *moves)
{
    for (int row = 0; row < map->nbr_line; ++row)
        mvprintw(row, 0, "%s", map->map[row]);
    *c = getch();
    move_P(map, *c, moves);
    if (*c == ' ')
        restart(map);
    *c = check_end(map, end);
}