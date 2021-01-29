/*
** EPITECH PROJECT, 2019
** put.c
** File description:
** PUT EVERYTHING INTO *EVERYTHING*
*/

#include <unistd.h>
#include <stdlib.h>

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