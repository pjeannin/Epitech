/*
** EPITECH PROJECT, 2020
** my_strfind
** File description:
** finds a word in a string
*/

#include "../../include/my.h"

int part_comp(char *str, char *look)
{
    while (*look) {
        if (*str != *look) {
            return (0);
        }
        ++look;
        ++str;
    }
    return (1);
}

int my_strfind(char *str, char *look)
{
    for (int it = 0; *str; ++it) {
        if (part_comp(str, look) == 1)
            return (it);
        ++str;
    }
    return (-1);
}
