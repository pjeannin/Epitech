/*
** EPITECH PROJECT, 2019
** add .c
** File description:
** inf add
*/
#include<stdlib.h>

void compute(char *,char *, int, char *);
char *my_revstr(char *);
void remov_0(char *);
void my_putstr(char *);
char *init(char *, char *, char *);

void add(char *nb1, char *nb2)
{
    int c;
    int r = 0;
    char *res;
    char *nb;

    res = init(res, nb1, nb2);
    if (res == NULL)
        return;
    compute(nb1, nb2, r, res);
    res = my_revstr(res);
    remov_0(res);
    my_putstr(res);
}