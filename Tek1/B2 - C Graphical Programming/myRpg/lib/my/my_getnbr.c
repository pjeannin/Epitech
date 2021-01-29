/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** my_getnbr.c
*/

#include <stdio.h>

int check(int *i, char const *str)
{
    int b = 0;

    while (str[*i] == '-' || str[*i] == '+') {
        if (str[*i] == '-')
            b++;
        *i = *i + 1;
    }
    if (!b % 2)
        return (1);
    return (-1);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int e = 0;
    int s;
    double count = 0.1;
    int tmp = 0;
    int nbr = 0;

    s = check(&i, str);
    tmp = i;
    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
        count *= 10;
        i++;
    }
    while (str[tmp] != '\0' && (str[tmp] >= '0' && str[tmp] <= '9')) {
        nbr = nbr + (str[tmp] - 48) * count;
        count *= 0.1;
        tmp++;
    }
    nbr = nbr * s;
    return (nbr);
}