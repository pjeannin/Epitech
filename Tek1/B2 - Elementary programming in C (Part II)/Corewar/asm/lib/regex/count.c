/*
** EPITECH PROJECT, 2020
** count
** File description:
** count
*/

#include "../../include/regex.h"

int count_sep(char *expression)
{
    int ret = 0;

    while (*expression) {
        while (*expression && *expression != '[') {
            ++expression;
            ++ret;
        }
        while (*expression && *expression != ']') {
            ++expression;
        }
    }
    return (ret);
}

int count_expr(char *expression)
{
    int ret = 0;

    while (*expression) {
        while (*expression && *expression != '[') {
            ++expression;
        }
        ret += (*expression == '[');
        while (*expression && *expression != ']') {
            ++expression;
        }
    }
    return (ret);
}

int count_patterns(char *expression)
{
    int ret = 0;

    while (*expression && *expression != ']') {
        ret += (*expression == '-');
        ++expression;
    }
    return (ret);
}
