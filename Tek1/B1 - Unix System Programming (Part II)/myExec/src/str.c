/*
** EPITECH PROJECT, 2019
** str.c
** File description:
** solo stumper 2
*/

#include <unistd.h>

int str_len(char *str)
{
    int len = 0;

    while (*str++)
        ++len;
    return (len);
}

void put_str(char *str)
{
    write(1, str, str_len(str));
}

void put_str_error(char *str)
{
    write(2, str, str_len(str));
}

void put_char(char c)
{
    write(1, &c, 1);
}
