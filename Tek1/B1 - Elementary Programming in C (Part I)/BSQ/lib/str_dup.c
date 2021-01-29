/*
** EPITECH PROJECT, 2019
** strdup.c
** File description:
** STRING ARE SEXY
*/

#include <stdlib.h>
#include "bsq.h"

char *str_dup(char *src)
{
    char *dest = (char*)malloc((sizeof(char) * str_len(src)) + 1);
    char *origin = dest;

    while (*src)
        *dest++ = *src++;
    *dest = 0;
    return (origin);
}