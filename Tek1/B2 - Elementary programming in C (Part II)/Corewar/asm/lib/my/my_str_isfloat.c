/*
** EPITECH PROJECT, 2020
** my_str_isfloat
** File description:
** check if a string is a float
*/

#include "../../include/my.h"

int my_str_isfloat(char const *str)
{
    if (str == NULL)
        return (0);
    while (*str == '+' || *str == '-')
        ++str;
    while (*str != '.') {
        if (ISNUM(*str) == 0)
            return (0);
        ++str;
        if (!(*str))
            return (1);
    }
    ++str;
    while (*str) {
        if (ISNUM(*str) == 0)
            return (0);
        ++str;
    }
    return (1);
}
