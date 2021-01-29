/*
** EPITECH PROJECT, 2019
** my_compute_square_root.c
** File description:
** compute square root
*/

int my_compute_square_root(int nb)
{
    int res = 0;

    while (res <= nb) {
        if (res * res == nb)
            return (res);
        else
            res += 1;
    }
    return (0);
}
