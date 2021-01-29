/*
** EPITECH PROJECT, 2020
** char_from_int.c
** File description:
** runner
*/

#include "my_rpg.h"

void str_rev(char *str)
{
    int i = 0;
    int j = (my_strlen(str) - 1);
    char tmp;

    while (i < j) {
        tmp = str[i];
        str[i++] = str[j];
        str[j--] = tmp;
    }
}

int find_len(int nbr)
{
    int len = 0;

    while (nbr > 0) {
        ++len;
        nbr /= 10;
    }
    return (len);
}

char *one_number(int nbr)
{
    char *n = malloc(sizeof(char) * 2);

    if (n == NULL)
        return (NULL);
    n[0] = nbr | 48;
    n[1] = '\0';
    return (n);
}

char *char_from_int(int nbr)
{
    int len = find_len(nbr);
    int i = 0;
    char *n;

    if (len == 0)
        return ("0");
    if (len == 1)
        return (one_number(nbr));
    n = malloc(sizeof(char) * len + 1);
    if (n == NULL)
        return (NULL);
    while (nbr > 0) {
        n[i] = (nbr % 10) | 48;
        ++i;
        nbr /= 10;
    }
    n[i] = '\0';
    str_rev(n);
    return (n);
}