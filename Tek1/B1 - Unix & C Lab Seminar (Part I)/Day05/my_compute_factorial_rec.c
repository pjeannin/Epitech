/*
** EPITECH PROJECT, 2019
** my_compute_factorial_rec.c
** File description:
** recursive fonction factorial
*/

int my_compute_factorial_rec (int nb)
{
    int res;

    if (12 < nb)
        return (0);
    if (nb == 0)
        return (1);
    if (0 > nb)
        return (0);
    res = my_compute_factorial_rec(nb - 1) * nb;
    return (res);
}
