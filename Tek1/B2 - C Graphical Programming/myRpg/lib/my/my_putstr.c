/*
** EPITECH PROJECT, 2019
** Day07
** File description:
** putstr
*/

#include "my.h"

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}