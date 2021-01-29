/*
** EPITECH PROJECT, 2020
** freeif
** File description:
** frees if it exist
*/

#include "../../include/my.h"
#include <stdarg.h>

int freeif(void *elem)
{
    if (elem) {
        free(elem);
        return (1);
    }
    return (0);
}

int freeif_2d(void **elem)
{
    void **tmp = elem;

    if (elem == NULL)
        return (0);
    while (*tmp) {
        freeif(*tmp);
        tmp++;
    }
    free(elem);
    return (1);
}

void multi_free(char *str, ...)
{
    va_list list;

    va_start(list, str);
    while (*str) {
        switch (*str) {
        case '1':
            freeif(va_arg(list, void *));
            break;
        case '2':
            freeif_2d(va_arg(list, void **));
            break;
        default:
            my_printf(2, "Unknown argument : '%c'\n", *str);
            return;
        }
        ++str;
    }
}
