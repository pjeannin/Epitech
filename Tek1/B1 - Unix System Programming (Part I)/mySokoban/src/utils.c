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

int usage(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        write(1, "USAGE\n    ./my_sokoban map\nDESCRIPTION\n", 42);
        write(1, "    map file representing the warehouse map, containing", 55);
        write(1, " ‘#’ for walls,\n        ‘P’ for the player, ‘X’", 48);
        write(1, " for boxes and ‘O’ for storage locations.", 45);
        return (1);
    }
    return (0);
}

int stat_test(struct stat file)
{
    if (file.st_size == 0)
        error_message("Empty file");
    if ((file.st_mode & S_IFMT) != S_IFREG)
        error_message("Not regular file");
    file.st_mode -= S_IFREG;
    if ((file.st_mode) % 8 != (unsigned short)7
        && (file.st_mode) % 8 != (unsigned short)6
        && (file.st_mode) % 8 != (unsigned short)4
        && (file.st_mode / 8) % 8 != (unsigned short)7
        && (file.st_mode / 8) % 8 != (unsigned short)6
        && (file.st_mode / 8) % 8 != (unsigned short)4
        && (file.st_mode / 80) % 8 != (unsigned short)7
        && (file.st_mode / 80) % 8 != (unsigned short)6
        && (file.st_mode / 80) % 8 != (unsigned short)4)
        error_message("Not right acces");
    return (0);
}

int error_handling(int ac, char **av)
{
    struct stat file;

    if (ac != 2) {
        write(2, "incorrect number of arguments, use '-h'", 39);
        return (1);
    }
    stat(av[1], &file);
    stat_test(file);
    return (0);
}

void move_P(map_t *map, int c, int *end)
{
    switch (c) {
        case KEY_LEFT: {
            move_left(map);
            ++(*end);
            break;
        } case KEY_RIGHT: {
            move_right(map);
            ++(*end);
            break;
        } case KEY_UP:
            move_up(map);
            ++(*end);
            break;
        case KEY_DOWN: {
            move_down(map);
            ++(*end);
            break;
        }
    }
}

char check_end(map_t *map, int *end)
{
    char c = chek_nomove(map);

    if (c == ' ') {
        *end = 1;
        return (' ');
    }
    for (int i = 0; i < map->nbr_line; ++i)
        for (int j = 0; map->map[i][j] != '\n'; ++j)
            if (map->initial_map[i][j] == 'O' && map->map[i][j] != 'X')
                return ('f');
    return (' ');
}