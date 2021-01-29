/*
** EPITECH PROJECT, 2019
** Day07
** File description:
** prime sup
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int a = nb;

    if (nb <= 2) {
        return (2);
    }
    while (my_is_prime(a) != 1) {
        a++;
    }
    return (a);
}
