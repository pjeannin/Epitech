/*
** EPITECH PROJECT, 2019
** my_compute_power_rec.c
** File description:
** recursive function power
*/

int my_compute_power_rec(int nb, int p)
{
    int res = nb;

    if (0 == p)
        return (1);
    if (0 > p)
        return (0);
    res = res * my_compute_power_rec(nb, p - 1);
    return (res);
}
