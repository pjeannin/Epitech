/*
** EPITECH PROJECT, 2019
** my_compute_power_it.c
** File description:
** iterative fonction power
*/

int my_compute_power_it (int nb, int p)
{
    int res = nb;

    if(0 == p)
        return (1);
    if (0 > p)
        return (0);
    for (int i = 1; i < p; ++i)
        res = res * nb;
    return (res);
}

