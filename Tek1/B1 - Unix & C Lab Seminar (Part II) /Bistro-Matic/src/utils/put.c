/*
** EPITECH PROJECT, 2019
** put.c
** File description:
** PUT EVERYTHING INTO *EVERYTHING*
*/

#include <unistd.h>
#include <stdlib.h>
#include "bistromatic.h"

void put_char(char c)
{
    write(1, &c, 1);
}

void put_str(char *str)
{
    while (*str)
        write(1, str++, 1);
}

void __put_nbr(int nbr)
{
    char c = ((nbr % 10) | 48);

    nbr /= 10;
    if (nbr)
        __put_nbr(nbr);
    write(1, &c, 1);
}

void put_nbr(int nbr)
{
    if (nbr < 0) {
        write(1, "-", 1);
        nbr *= -1;
    }
    __put_nbr(nbr);
}

char *char_from_nbr(int nbr)
{
    int nb_lenght = 0;
    int neg = 0;
    int i = 0;
    int nbr_cpy = nbr;
    char *res;

    put_str("dans char_from_nbr : ");
    put_nbr(nbr),
    put_char('\n');
    while (nbr_cpy) {
        nbr_cpy /= 10;
        ++nb_lenght;
    }
    res = malloc(sizeof(char) * nb_lenght + 2);
    if (nbr < 0) {
        neg = 1;
        nbr *= -1;
    }
    while(nbr) {
        res[i] = (nbr % 10) | 48;
        ++i;
        nbr /= 10;
    }
    put_str("i a la fin : ");
    put_nbr(i),
    put_char('\n');
    str_rev(res);
    if (neg) {
        while (i > 0) {
            res[i] = res[i - 1];
            --i;
        }
        res[i] = '-';
    }
    return (res);
}