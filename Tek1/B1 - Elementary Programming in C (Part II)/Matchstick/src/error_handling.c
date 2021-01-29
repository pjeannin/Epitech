/*
** EPITECH PROJECT, 2020
** error_handling.c
** File description:
** matchstick
*/

#include "matchstick.h"

int error_handling(char *line, char *matches, int ac)
{
    if (ac != 3)
        return (1);
    for (int i = 0; line[i]; ++i)
        if (line[i] < '0' || line[i] > '9')
            return (1);
    for (int i = 0; matches[i]; ++i)
        if (matches[i] < '0' || matches[i] > '9')
            return (1);
    if (str_len(line) > 2)
        return (1);
    if (str_len(matches) > 2)
        return (1);
    if (str_len(line) == 1 && line[0] == '0')
        return (1);
    if (str_len(matches) == 1 && matches[0] == '0')
        return (1);
    return (0);
}