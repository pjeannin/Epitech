/*
** EPITECH PROJECT, 2020
** square.c
** File description:
** square operations
*/

int my_sqr(int nb, int pow)
{
    int ret = 1;

    for (int i = 0; i < pow; ++i) {
        ret *= nb;
    }
    return (ret);
}

int my_sqrt(int nb)
{
    for (int i = 0; i < nb; ++i) {
        if (my_sqr(i, 2) == nb)
            return (i);
    }
    return (0);
}
