/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** print a character
*/

#include<unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}
