/*
** EPITECH PROJECT, 2020
** get_line.c
** File description:
** get_line
*/

#include "../include/solver.h"

char *get_line(int fd)
{
    char *line = malloc(sizeof(char) * 100);
    char *buf = malloc(sizeof(char) * 2);
    int index = 0;

    buf[0] = 'n';
    while (read(fd, buf, 1) > 0 && *buf != '\n' && *buf != '\0') {
        line[index] = *buf;
        ++index;
    }
    if (index == 0) {
        free(line);
        return ((char *)-1);
    }
    line[index] = '\0';
    free(buf);
    return (line);
}