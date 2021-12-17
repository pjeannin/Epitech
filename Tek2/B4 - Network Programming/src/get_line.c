/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myftp-pierre.jeannin
** File description:
** get_line
*/

#include "ftp.h"

char *get_line(int fd)
{
    char *buf = malloc(sizeof(char) * 32);
    if (!buf)
            return (NULL);
    char read_char = 0;

    for (int i = 0; read_char != '\n';) {
        if (read(fd, &read_char, 1) == 1) {
            buf[i++] = read_char;
        }
        if (read_char == '\n')
            buf[i - 1] = '\0';
    }

    return (buf);
}