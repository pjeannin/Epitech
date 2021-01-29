/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverses a string
*/

#include "../../include/my.h"

int my_revstr(char *str)
{
    int len = my_strlen(str);
    int mid = len / 2;
    char tmp;

    if (str == NULL)
        return (84);
    for (int i = 0; i < mid; ++i) {
        tmp = str[i];
        str[i] = str[--len];
        str[len] = tmp;
    }
    return (0);
}
