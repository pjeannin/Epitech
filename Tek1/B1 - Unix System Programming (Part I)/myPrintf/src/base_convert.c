/*
** EPITECH PROJECT, 2019
** base_convert.c
** File description:
** my_printf
*/

#include <stdlib.h>
#include <unistd.h>

void rev_str(char *str);

char pos_in_base(char *base, int nb)
{
    int i = 0;

    while (i < nb) {
        ++base;
        ++i;
    }
    return (*base);
}

int nb_len(int nbr)
{
    int len = 0;

    while (nbr > 0) {
        ++len;
        nbr /= 10;
    }
    return (len);
}

char *base_convert(long long nbr, char *base, int base_len)
{
    char *n = malloc(sizeof(char) * (nb_len(nbr) * base_len) * 5);
    int i = 0;

    while (nbr > 0) {
        n[i] = pos_in_base(base, (nbr % base_len));
        nbr /= base_len;
        ++i;
    }
    n[i] = '\0';
    rev_str(n);
    return (n);
}

char *base_convert_ptr(unsigned long long nbr, char *base, int base_len)
{
    char *n = malloc(sizeof(char) * (nb_len(nbr) * base_len) * 5);
    int i = 0;

    while (nbr > 0) {
        n[i] = pos_in_base(base, (nbr % base_len));
        nbr /= base_len;
        ++i;
    }
    n[i] = '\0';
    rev_str(n);
    write(1, n, 12);
    return (n);
}