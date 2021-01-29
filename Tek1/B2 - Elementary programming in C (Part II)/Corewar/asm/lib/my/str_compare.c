/*
** EPITECH PROJECT, 2020
** str_compare
** File description:
** compare two string in alphabetical order
*/

#include "../../include/my.h"

int str_compare(char *str1, char *str2)
{
    int k = 0;

    while (str1[k] != '\0') {
        if (!(str2[k]))
            return (0);
        if (str1[k] > str2[k])
            return (0);
        else if (str2[k] > str1[k])
            return (1);
        ++k;
    }
    return (1);
}

bool flag_cmp(char const crt, char const *flag)
{
    for (; *flag; ++flag)
        if (*flag == crt)
            return (true);
    return (false);
}