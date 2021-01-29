/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** my_sokoban
*/

#include <ncurses.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_sokoban.h"

int my_sokoban(char *filepath)
{
    int end = 0;
    int moves = 0;
    struct stat file;
    int col, line = 0;
    map_t *map;
    int c = 'h';

    map = init_game(filepath);
    while (c != ' ') {
        col = COLS;
        line = LINES;
        clear();
        if (map->nbr_line <= LINES && map->nbr_col <= COLS)
            game(&c, map, &end, &moves);
        else
            mvprintw(LINES / 2, COLS / 2 - str_len(LARGE) / 2, LARGE);
        refresh();
    }
    end_game(map);
    return (end);
}

int main(int ac, char ** av)
{
    int end;

    if (usage(ac, av))
        return (84);
    if (error_handling(ac, av))
        return (84);
    end = my_sokoban(av[1]);
    return (end);
}