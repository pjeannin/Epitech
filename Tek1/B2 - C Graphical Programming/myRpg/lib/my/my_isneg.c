/*
** EPITECH PROJECT, 2019
** Day07
** File description:
** isneg
*/

#include "my.h"

void my_isneg(int nb)
{
    if (nb < 0)
        my_putchar('N');
    else
        my_putchar('P');
}
