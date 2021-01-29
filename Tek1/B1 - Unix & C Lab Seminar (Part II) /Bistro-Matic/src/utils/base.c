/*
** EPITECH PROJECT, 2019
** base.c
** File description:
** BASE ARE SEXY
*/

#include <stdlib.h>
#include "bistromatic.h"

int pos_in_base(char c, char *base)
{
    for (int i = 0; base[i]; i++)
        if (c == base[i])
            return (i);
    return (-1);
}

long any_base_to_decimal(char *expr, char *base, int base_len, int expr_len)
{
    int cur_nbr;
    long n = 0;
    int i = (expr_len - 1);
    int neg = 1;
    int pow = 1;

    if (expr[0] == '-') {
        neg = -1;
    }
    while (i != -1 && expr[i] != '-') {
        cur_nbr = (pos_in_base(expr[i--], base) * pow);
        n += cur_nbr;
        pow *= base_len;
    }
    n *= neg;
    return (n);
}

char *decimal_to_any_base(int nbr, char *base, int base_len)
{
    char *res;
    int nb_len = 0;
    int neg = 0;
    int nbr_cpy = nbr;
    int cur_nbr;
    int i = 0;

    if (nbr < 0) {
        nbr *= -1;
        neg = 1;
    }
    while (nbr_cpy != 0) {
        ++nb_len;
        nbr_cpy /= 10;
    }
    res = malloc(sizeof(char) * nb_len * base_len + 1);
    while (nbr) {
        cur_nbr = nbr % base_len;
        res[i] = base[cur_nbr];
        nbr /= base_len;
        ++i;
    }
    if (neg)
        res[i++] = '-';
    res[i] = '\0';
    str_rev(res);
    return (res);
}