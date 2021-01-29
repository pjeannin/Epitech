/*
** EPITECH PROJECT, 2020
** getters
** File description:
** getters
*/

#include "../../include/regex.h"

patterns_t ***get_patterns(char *expression)
{
    int nb = count_expr(expression);
    int act = 0;
    patterns_t ***patterns = malloc(sizeof(patterns_t **) * (nb + 1));

    if (patterns == NULL)
        return (NULL);
    while (*expression) {
        if (*expression == '[') {
            patterns[act++] = fill_patterns(expression);
        }
        ++expression;
    }
    patterns[act] = NULL;
    return (patterns);
}

int get_length(char *expression)
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

char *get_format(char *expression)
{
    int length = get_length(expression);
    char *format = malloc(sizeof(char) * (length + 1));

    if (format_string(format, expression) == 1)
        return (NULL);
    return (format);
}
