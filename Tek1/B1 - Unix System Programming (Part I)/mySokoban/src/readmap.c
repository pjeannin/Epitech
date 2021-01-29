/*
** EPITECH PROJECT, 2019
** readmap.c
** File description:
** my_sokoban
*/

#include "my_sokoban.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *readline(int filesize, int *nbread, int fd)
{
    char *line = malloc(sizeof(char) * filesize);
    char *curchar = malloc(sizeof(char) * 3);

    *curchar = 'f';
    for (int i = 0; *curchar != '\n'; ++i) {
        read(fd, curchar, 1);
        line[i] = *curchar;
        ++(*nbread);
    }
    return (line);
}

char **readmap(char *filepath, map_t *maps)
{
    int fd = open(filepath, O_RDONLY);
    char **map;
    int nbread = 0;
    struct stat file;

    stat(filepath, &file);
    map = malloc(sizeof(char) * file.st_size);
    for (int i = 0; nbread < file.st_size - 2; ++i) {
        map[i] = readline(file.st_size, &nbread, fd);
        ++(maps->nbr_line);
    }
    close(fd);
    return (map);
}

void free_map_error(map_t *map)
{
    for (int i = 0; i < map->nbr_line; ++i) {
        free(map->map[i]);
        free(map->initial_map[i]);
    }
    free(map->map);
    free(map->initial_map);
    free(map);
    write(2, "Invalid map", 11);
    exit(84);
}

void check_map(map_t *map, int *count_P, int *count_O, int *nb_col, int i)
{
    *nb_col = 0;
    for (int j = 0; map->map[i][j] != '\n'; ++j) {
        if (map->map[i][j] != 'X' && map->map[i][j] != 'P'
        && map->map[i][j] != ' ' && map->map[i][j] != 'O'
        && map->map[i][j] != '#' && map->map[i][j] != '\n')
            free_map_error(map);
        if (map->map[i][j] == 'O')
            ++(*count_O);
        if  (map->map[i][j] == 'X')
            --(*count_O);
        if (map->map[i][j] == 'P') {
            ++(*count_P);
            map->posx = j;
            map->posy = i;
        }
        ++(*nb_col);
    }
    if (*nb_col > map->nbr_col)
        map->nbr_col = *nb_col;
}

map_t *init_map(char *filepath)
{
    map_t *map = malloc(sizeof(map_t));
    int count_O = 0;
    int count_P = 0;
    int nb_col;

    map->nbr_line = 0;
    map->nbr_col = 0;
    map->initial_map = readmap(filepath, map);
    map->map = readmap(filepath, map);
    map->nbr_line /= 2;
    for (int i = 0; i < map->nbr_line; ++i)
        check_map(map, &count_P, &count_O, &nb_col, i);
    if (count_O != 0 || count_P != 1)
        free_map_error(map);
    map->init_posx = map->posx;
    map->init_posy = map->posy;
    return (map);
}