/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** matchstick
*/

#include <unistd.h>
#include "matchstick.h"

int str_len(char *str)
{
    int len = 0;

    while (*str++)
        ++len;
    return (len);
}

void put_char(char c)
{
    write(1, &c, 1);
}

void put_str(char *str)
{
    write(1, str, str_len(str));
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