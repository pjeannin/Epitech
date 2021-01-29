/*
** EPITECH PROJECT, 2020
** str.c
** File description:
** utils
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

void put_error_str(char *str)
{
    write(2, str, str_len(str));
}