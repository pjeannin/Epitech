/*
** EPITECH PROJECT, 2020
** get_line.c
** File description:
** get_line
*/

#include "my_defender.h"

char *get_line(int fd)
{
    char *line = malloc(sizeof(char) * 100);
    char *buf = malloc(sizeof(char) * 2);
    int index = 0;

    if (line == NULL || buf == NULL)
        return (NULL);
    buf[0] = 'n';
    while(read(fd, buf, 1) && *buf != '\n') {
        line[index] = *buf;
        ++index;
    }
    line[index] = '\0';
    free(buf);
    return (line);
}