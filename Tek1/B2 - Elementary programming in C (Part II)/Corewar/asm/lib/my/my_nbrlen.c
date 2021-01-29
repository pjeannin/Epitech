/*
** EPITECH PROJECT, 2020
** my_nbrlen
** File description:
** my_nbrlen
*/

#include "../../include/my.h"

int my_nbrlen(int nb)
{
    int ret = 2;

    if (nb < 0) {
        nb *= -1;
        ++ret;
    }
    while (nb >= 10) {
        nb /= 10;
        ++ret;
    }
    return (ret);
}
