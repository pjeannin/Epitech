/*
** EPITECH PROJECT, 2019
** inint.c
** File description:
** inf add
*/
#include<stdlib.h>

int find_len(char *, char *);
char *my_revstr(char *);

char *init(char *res, char *nb1, char *nb2)
{
    int len;

    len = find_len(nb1, nb2);
    nb1 = my_revstr(nb1);
    nb2 = my_revstr(nb2);
    res = malloc(sizeof(char) * len);
    return (res);
}