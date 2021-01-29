/*
** EPITECH PROJECT, 2019
** put_str.c
** File description:
** STRING ARE SEXY
*/

#include <unistd.h>

void put_str(char const *str)
{
    while (*str)
        write(1, str++, 1);
}