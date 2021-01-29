/*
** EPITECH PROJECT, 2019
** error_message.c
** File description:
** my_sokoban
*/

#include <stdlib.h>
#include <unistd.h>

int str_len(char *str)
{
    int len = 0;

    while (*str++)
        ++len;
    return (len);
}

void error_message(char *str)
{
    write(2, str, str_len(str));
    exit(84);
}