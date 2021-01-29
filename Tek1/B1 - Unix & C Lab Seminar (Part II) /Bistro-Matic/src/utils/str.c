/*
** EPITECH PROJECT, 2019
** str.c
** File description:
** STRING ARE SEXY
*/

#include <stdlib.h>

int str_len(const char *str)
{
    int n = 0;

    while (*str++)
        n++;
    return (n);
}

char *str_dup(const char *src)
{
    char *dest = malloc(sizeof(char) * str_len(src) + 1);
    char *origin = dest;

    while (*src)
        *dest++ = *src++;
    *dest = 0;
    return (origin);
}

void str_rev(char *str)
{
    int i = 0;
    int j = (str_len(str) - 1);
    char tmp;

    while (i < j) {
        tmp = str[i];
        str[i++] = str[j];
        str[j--] = tmp;
    }
}
