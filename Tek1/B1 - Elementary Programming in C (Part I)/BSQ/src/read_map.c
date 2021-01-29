/*
** EPITECH PROJECT, 2019
** read_map.c
** File description:
** BSQ
*/

#include "bsq.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void read_line(char *buf, int fd)
{
    char *cur_char = malloc(sizeof(char));
    int r;

    *cur_char = 'n';
    if (cur_char == NULL) {
        write(2, "malloc cur_char faild", 21);
        exit(84);
    }
        for (int i = 0; *cur_char != '\n'; ++i) {
            read(fd, cur_char, 1);
            buf[i] = *cur_char;
    }
    free(cur_char);
}

char **__read_map(char **map, int *nbr_line, int *nbr_col, int fd)
{
    map[0] = malloc(sizeof(char) * 1000000);
    if (map[0] == NULL) {
        write(2, "malloc map[0] faild", 20);
        exit(84);
    }
    read_line(map[0], fd);
    for (int i = 0; map[0][i + 1]; ++i)
        ++(*nbr_col);
    for (int i = 1; i < (*nbr_line); ++i) {
        map[i] = malloc(sizeof(char) * (*nbr_col) + 1);
        if (map[i] == NULL) {
            write(2, "malloc map[i] faild", 20);
            exit(84);
        }
        read_line(map[i], fd);
    }
    close(fd);
    return (map);
}

char **read_map(char *filepath, int *nbr_line, int *nbr_col)
{
    char *buf = malloc(sizeof(char) * 11);
    char **map;
    int fd = open(filepath, O_RDONLY);

    if (buf == NULL) {
        write(2, "malloc buf faild", 17);
        exit(84);
    }
    read_line(buf, fd);
    *nbr_line = my_getnbr(buf);
    free(buf);
    map = malloc(sizeof(char *) * (*nbr_line));
    if (map == NULL) {
        write(2, "malloc map faild", 17);
        exit(84);
    }
    map = __read_map(map, nbr_line, nbr_col, fd);
    return (map);
}