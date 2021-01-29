/*
** EPITECH PROJECT, 2020
** my_atof
** File description:
** gets a float from a string
*/

#include "../../include/my.h"

int neg_check(char c)
{
    return (c == '-');
}

float my_atof(char const *str)
{
    float ret = 0;
    float div = 10;
    int neg = 0;

    if (my_str_isfloat(str) == 0)
        return (0);
    while (*str == '+' || *str == '-')
        neg += neg_check(*str++);
    while (ISNUM(*str)) {
        ret = ret * 10 + (*str - 48);
        ++str;
    }
    if (*str++ != '.')
        return (ret * ((neg & 1) ? (-1) : 1));
    while (*str) {
        ret += (float)(*str - 48) / div;
        div *= 10;
        ++str;
    }
    return (ret * ((neg & 1) ? (-1) : 1));
}

float my_atofe(char const *str)
{
    float ret = 0;
    float div = 10;
    int neg = 0;

    if (str == NULL)
        return (0);
    while (*str == '+' || *str == '-')
        neg += neg_check(*str++);
    while (ISNUM(*str)) {
        ret = ret * 10 + (*str - 48);
        ++str;
    }
    if (*str++ != '.')
        return (ret * ((neg & 1) ? (-1) : 1));
    while (ISNUM(*str)) {
        ret += (float)(*str - 48) / div;
        div *= 10;
        ++str;
    }
    return (ret * ((neg & 1) ? (-1) : 1));
}

float my_getfloat(char const *str)
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
        return (my_atofe(tmp + 1));
    }
    return (my_atofe(str));
}
