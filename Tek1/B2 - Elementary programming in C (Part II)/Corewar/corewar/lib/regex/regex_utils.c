/*
** EPITECH PROJECT, 2020
** regex utils
** File description:
** regex utils
*/

#include "../../include/regex.h"

int format_string(char *format, char *expression)
{
    int act = 0;

    while (*expression) {
        if (*expression && *expression == ']')
            ++expression;
        while (*expression && *expression != '[') {
            format[act++] = *expression;
            ++expression;
        }
        if (*expression && *expression == '[')
            format[act++] = 17;
        while (*expression && *expression != ']') {
            ++expression;
        }
    }
    format[act] = '\0';
    return (0);
}

void free_patterns(patterns_t ***patterns)
{
    if (patterns == NULL)
        return;
    for (int i = 0; patterns[i]; ++i) {
        for (int j = 0; patterns[i][j]; ++j)
            free(patterns[i][j]);
        free(patterns[i]);
    }
    free(patterns);
}

int check_patterns(char _char, patterns_t **patterns)
{
    if (patterns == NULL)
        return (0);
    for (int i = 0; patterns[i]; ++i) {
        if (_char >= patterns[i]->from && _char <= patterns[i]->to)
            return (1);
    }
    return (0);
}

int deep_checkvar(char *str, regex_t *regex, int *act_p, int *act_form)
{
    if (regex->format[*act_form + 1] == *str) {
        *act_p += 1;
        *act_form += 2;
    } else if (check_patterns(*str, regex->patterns[*act_p]) == 0) {
        return (0);
    }
    return (1);
}
