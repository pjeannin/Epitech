/*
** EPITECH PROJECT, 2020
** put_nbr.c
** File description:
** minishell
*/

#include <unistd.h>

void putnbr(int nbr)
{
    char c = ((nbr % 10) | 48);

    nbr /= 10;
    if (nbr)
        putnbr(nbr);
    write(1, &c, 1);
}

void put_nbr(int nbr)
{
    if (nbr < 0) {
        write(1, "-", 1);
        nbr *= -1;
    }
    putnbr(nbr);
}