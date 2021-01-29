/*
** EPITECH PROJECT, 2020
** contains
** File description:
** check if a string contains something
*/

#include "../../include/my.h"

static int check_contains(char str, char *check)
{
    for (int j = 0; check[j]; ++j)
        if (str == check[j])
            return (1);
    return (0);
}

int contains(char *str, char *check)
{
    while (str && *str) {
        if (check_contains(*str, check) == 1)
            return (1);
        str++;
    }
    return (0);
}
