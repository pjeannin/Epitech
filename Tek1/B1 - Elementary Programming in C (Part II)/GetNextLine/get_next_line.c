/*
** EPITECH PROJECT, 2019
** get_next_line.c
** File description:
** GNL
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int str_len(char *str)
{
    int len = 0;

    while (*str++)
        ++len;
    return (len);
}

int check_end_line(char *str)
{
    for (int i = 0; i < str_len(str); ++i)
        if (str[i] == '\n')
            return (i);
    return (-1);
}

char *concat_str(char *str1, char *str2)
{
    char *str = malloc(sizeof(char) * str_len(str1) + str_len(str2) + 1);

    for (int i = 0; i < str_len(str1); ++i)
        str[i] = str1[i];
    for (int i = 0; i < str_len(str2); ++i)
        str[i + str_len(str1)] = str2[i];
    str[str_len(str1) + str_len(str2)] = '\0';
    return (str);
}

int count_end_line(char *str)
{
    int nb = 0;

    for (int i = 0; str[i]; ++i)
        if (str[i] == '\n')
            ++nb;
    return (nb);
}

char *split_remainder(char *remainder)
{
    int pos1 = -1;
    int pos2 = -1;
    int i = 0;
    char *return_v;

    for (int i = 0; pos2 == -1; ++i) {
        if (remainder[i] == '\n' && pos1 == -1)
            pos1 = i;
        if (remainder[i] == '\n' && pos1 != -1)
            pos2 = i;
    }
    return_v = malloc(sizeof(char) * pos2 - pos1 + 2);
    for (int i = 0; (i + pos1) < str_len(remainder); ++i)
        return_v[i] = remainder[i + pos1];
    return(return_v);
}

char *get_next_line(int fd)
{
    char *remainder = malloc(sizeof(char) * READ_SIZE + 1);
    static char *sremainder = NULL;
    char *return_value = malloc(sizeof(char) * READ_SIZE + 1);
    int nb_end_line = 0;
    int pos_end_line = 0;
    int read_char = read(fd, return_value, READ_SIZE);

    if (fd == -1)
        return (NULL);
    if (sremainder != NULL) {
        nb_end_line = count_end_line(sremainder);
        if (nb_end_line > 1)
            sremainder = split_remainder(sremainder);
        if (nb_end_line == 1) {
            pos_end_line = check_end_line(sremainder);
            for (int i = 0; i < READ_SIZE - (pos_end_line + 1); ++i)
                sremainder[i] = sremainder[i + pos_end_line + 1];
            sremainder[READ_SIZE - (pos_end_line + 1)] = '\0';
        }
    }
    if (read_char < READ_SIZE) {
        return_value[read_char] = '\0';
        pos_end_line = check_end_line(return_value);
        if (pos_end_line != -1) {
            return_value[pos_end_line] = '\0';
            return (return_value);
        }
    } else
        return_value[READ_SIZE] = '\0';
    if (sremainder != NULL)
        return_value = concat_str(sremainder, return_value);
    while (read_char == READ_SIZE) {
        read_char = read(fd, remainder, READ_SIZE);
        remainder[read_char] = '\0';
        sremainder = remainder;
        return_value = concat_str(return_value, remainder);
        pos_end_line = check_end_line(return_value);
        if (pos_end_line != -1) {
            return_value[pos_end_line] = '\0';
            return (return_value);
        }
    }
    return (return_value);
}