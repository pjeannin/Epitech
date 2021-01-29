/*
** EPITECH PROJECT, 2019
** put.c
** File description:
** PUT EVERYTHING INTO *EVERYTHING*
*/

#include <unistd.h>
#include <stdlib.h>

void put_char(char c)
{
    write(1, &c, 1);
}

void put_str(char *str)
{
    while (*str)
        write(1, str++, 1);
}