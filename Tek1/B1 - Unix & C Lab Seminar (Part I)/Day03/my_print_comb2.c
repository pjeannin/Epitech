/*
** EPITECH PROJECT , 2019
** my_print_comb2.c
** File description :
** displays, in ascending order, all the different combinations of two two-digit numbers
*/
#include <unistd.h>

void show_nbr (int nb)
{
    if (nb < 10) {
        my_putchar ('0');
        my_put_nbr (nb);
    }
    else
        my_put_nbr(nb);
}

int my_print_comb2 (void)
{
    int nbl = 00;
    int nbr = 01;

    while (nbl <= 98 && nbr <= 99) {
        show_nbr (nbl);
        my_putchar (' ');
        show_nbr (nbr);
        if (nbl + nbr < 197) {
            my_putchar (',');
            my_putchar (' ');
        }
        nbr = nbr + 1;
        if (nbr == 100) {
            nbl = nbl + 1;
            nbr = nbl + 1;
        }
    }
    return (0);
}
