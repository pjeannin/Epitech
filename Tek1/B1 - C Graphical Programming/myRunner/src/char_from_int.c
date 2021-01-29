/*
** EPITECH PROJECT, 2020
** char_from_int.c
** File description:
** runner
*/

#include <stdlib.h>
#include "my_runner.h"

char *char_from_int(int nbr)
{
    int cpy = nbr;
    int len = 0;
    int i = 0;
    char *n;

    while (cpy > 0) {
        ++len;
        cpy /= 10;
    }
    if (len == 0)
        return ("0");
    n = malloc(sizeof(char) * len);
    while (nbr > 0) {
        n[i] = (nbr % 10) | 48;
        ++i;
        nbr /= 10;
    }
    n[i] = '\0';
    str_rev(n);
    return (n);
}