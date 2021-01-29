/*
** EPITECH PROJECT, 2019
** my_isneg.c
** File description:
** my_isneg
*/

#include <unistd.h>

int my_isneg(int n)
{
    if (n<0) {
        my_putchar('N');
    }
    else {
        my_putchar('P');
    }
    return (0);
}
