/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** reproduces atoi function
*/

#include "../../include/my.h"

int my_atoi(char const *str)
{
    int ret = 0;
    int neg = 0;

    if (my_str_isnum(str) != 0)
        return (0);
    while (*str == '+' || *str == '-') {
        if (*str == '-')
            ++neg;
        ++str;
    }
    while (*str) {
        ret *= 10;
        ret += *str - 48;
        ++str;
    }
    return (ret * ((neg & 1) ? (-1) : 1));
}

int my_atoie(char const *str)
{
    int ret = 0;
    int neg = 0;

    while (*str == '+' || *str == '-') {
        if (*str == '-')
            ++neg;
        ++str;
    }
    while (ISNUM(*str)) {
        ret *= 10;
        ret += *str - 48;
        ++str;
    }
    return (ret * ((neg & 1) ? (-1) : 1));
}

int my_getnbr(char const *str)
{
    char const *tmp = str;

    if (str == NULL)
        return (0);
    while (*str && ISNUM(*str) != 1) {
        ++str;
    }
    if (!*str)
        return (0);
    tmp = str - ((tmp != str) ? 1 : 0);
    if (*tmp == '-' || *tmp == '+') {
        while (*tmp == '-' || *tmp == '+') {
            --tmp;
        }
        return (my_atoie(tmp + 1));
    }
    return (my_atoie(str));
}
