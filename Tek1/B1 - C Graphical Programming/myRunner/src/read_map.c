/*
** EPITECH PROJECT, 2019
** read_map.c
** File description:
** BSQ
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int exit_readmap(int fd, char *str)
{
    close(fd);
    write(2, str, str_len(str));
    return (84);
}

void read_line(char *buf, int fd)
{
    char *curchar = malloc(sizeof(char));
    int i;

    if (curchar == NULL)
        exit_readmap(fd, "malloc read line failed");
    *curchar = 'n';
    for (i = 0; *curchar != '\n'; ++i) {
        read(fd, curchar, 1);
        buf[i] = *curchar;
    }
    buf[i] = '\0';
}

void free_malloc_map(char **map, int fd, int i)
{
    for (int j = 0; j < i; ++j)
        free(map[i]);
    free(map);
    exit_readmap(fd, "malloc line failed");
}

char **end_r_map(int *nb_col, int *nb_line, int fd, char **map)
{
    read_line(map[0], fd);
    *nb_col = str_len(map[0]);
    for (int i = 1; i < *nb_line; ++i) {
        map[i] = malloc(sizeof(char) * *nb_col);
        if (map[i] == NULL)
            free_malloc_map(map, fd, i);
        read_line(map[i], fd);
    }
    return (map);
}

char **read_map(char *filepath, int *nb_line, int *nb_col)
{
    char *buf = malloc(sizeof(char) * 11);
    char **map;
    int fd = open(filepath, O_RDONLY);

    if (buf == NULL)
        return ((char **)exit_readmap(fd, "malloc buf failed"));
    read_line(buf, fd);
    *nb_line = my_getnbr(buf);
    free(buf);
    map = malloc(sizeof(char) * *nb_line);
    if (map == NULL)
        return ((char **)exit_readmap(fd, "malloc map failed"));
    map[0] = malloc(sizeof(char) * 10000);
    if(map[0] == NULL) {
        free(map);
        return (exit_readmap(fd, "malloc line failed"));
    }
    map = end_r_map(nb_col, nb_line, fd, map);
    close(fd);
    return (map);
}