/*
** EPITECH PROJECT, 2019
** strdup.c
** File description:
** STRING ARE SEXY
*/

#include "lib.h"
#include <stdlib.h>

char *str_dup(char const *src)
{
    char *dest = (char*)malloc((sizeof(char) * str_len(src)) + 1);
    char *origin = dest;

    while (*src)
        *dest++ = *src++;
    *dest = 0;
    return (origin);
}