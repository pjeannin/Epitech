/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** my_strlen
*/

#include <stdlib.h>
#include "../../include/my.h"

unsigned int my_strlen(char const *str)
{
    char const *tmp = str;

    if (str == NULL)
        return (0);
    while (*str)
        ++str;
    return (str - tmp);
}

int my_strlen_crt(char const *str, char const end)
{
    char const *i = str;

    if (str == NULL || *str == end) return (0);
    for (; *i && *i != end; i++);
    return (i - str);

}

int my_strlen_flag(char const *str, char const *flag)
{
    register char const *i = str;

    for (;*i && flag_cmp(*i, flag) == 0; ++i);
    return (i - str);
}