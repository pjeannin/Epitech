/*
** EPITECH PROJECT, 2020
** regex
** File description:
** regex
*/

#include "../../include/regex.h"

regex_t create_regex(char *expression)
{
    regex_t new;

    new.patterns = get_patterns(expression);
    new.format = get_format(expression);
    return (new);
}

int check_regex(char *str, regex_t *regex)
{
    int act_p = 0;
    int act_form = 0;
    int ret = 1;

    if (str == NULL)
        return (0);
    while (*str) {
        if (regex->format[act_form] == '\0')
            return (0);
        if (regex->format[act_form] == 17) {
            ret = deep_checkvar(str, regex, &act_p, &act_form);
        } else {
            ret = (regex->format[act_form] != *str) ? 0 : 1;
            ++act_form;
        }
        if (ret == 0)
            return (0);
        ++str;
    }
    return (1);
}

void destroy_regex(regex_t *regex)
{
    if (regex == NULL)
        return;
    free_patterns(regex->patterns);
    if (regex->format)
        free(regex->format);
}
