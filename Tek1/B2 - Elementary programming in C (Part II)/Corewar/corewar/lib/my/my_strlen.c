/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** my_strlen
*/

#include <stdlib.h>

unsigned int my_strlen(char const *str)
{
    char const *tmp = str;

    if (str == NULL)
        return (0);
    while (*str)
        ++str;
    return (str - tmp);
}
