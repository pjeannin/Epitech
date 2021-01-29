/*
** EPITECH PROJECT, 2019
** sub.c
** File description:
** inf add
*/
#include<stdlib.h>

int comp(char *, char *);
void my_putcahr(char);
char *bigger(char *, char *);
char *init(char *, char *, char *);
void compute_sub(char *, char *, char *);
void my_putchar(char);

void sub(char *nb1, char *nb2)
{
    char *res;
    int big;
    char *tmp;

    big = comp(nb1, nb2);
    if (big == 0) {
        my_putchar('0');
        return;
    }
    if (big == 1) {
        nb1 = bigger(nb1, nb2);
        tmp = nb1;
        nb1 = nb2;
        nb2 = tmp;
    }
    res = init(res, nb1, nb2);
    if (res == NULL)
        return;
    compute_sub(nb1, nb2, res);
}