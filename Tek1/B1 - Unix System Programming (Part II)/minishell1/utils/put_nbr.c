/*
** EPITECH PROJECT, 2020
** put_nbr.c
** File description:
** minishell
*/

#include <unistd.h>

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