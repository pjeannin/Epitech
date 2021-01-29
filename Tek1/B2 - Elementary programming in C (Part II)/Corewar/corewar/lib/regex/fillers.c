/*
** EPITECH PROJECT, 2020
** fillers
** File description:
** fillers
*/

#include "../../include/regex.h"

patterns_t *fill_pattern(char *expression)
{
    patterns_t *pattern = malloc(sizeof(patterns_t));

    if (pattern == NULL)
        return  (NULL);
    pattern->from = *(expression - 1);
    pattern->to = *(expression + 1);
    return (pattern);
}

patterns_t **fill_patterns(char *expression)
{
    int nb = count_patterns(expression);
    int act = 0;
    patterns_t **patterns = malloc(sizeof(patterns_t *) * (nb + 1));

    if (patterns == NULL)
        return (NULL);
    while (*expression && *expression != ']') {
        if (*expression == '-')
            patterns[act++] = fill_pattern(expression);
        ++expression;
    }
    patterns[act] = NULL;
    return (patterns);
}
