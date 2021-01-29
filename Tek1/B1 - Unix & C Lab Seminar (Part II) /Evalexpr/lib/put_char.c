/*
** EPITECH PROJECT, 2019
** put_char.c
** File description:
** STRING ARE SEXY
*/

#include <unistd.h>

void put_char(char c)
{
    write(1, &c, 1);
}