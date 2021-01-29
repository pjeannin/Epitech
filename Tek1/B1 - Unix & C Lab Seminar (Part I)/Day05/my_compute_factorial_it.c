/*
** EPITECH PROJECT, 2019
** my_compute_factorial_it.c
** File description:
** factorial of a number
*/

int my_compute_factorial_it (int nb)
{
    int res = 1;
    
    if (12 < nb)
        return (0);
    if (0 == nb)
        return (1);
    if (0 > nb)
        return (0);
    for (int i = 1; i <= nb; ++i)
        res *= i;
    return (res);
}
