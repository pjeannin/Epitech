/*
** EPITECH PROJECT, 2019
** compute_sub.c
** File description:
** inf add
*/

void sub_compute(char *, char *, char *);
char *my_revstr(char *);
void remov_0(char *);
void my_putstr(char *);

void compute_sub(char *nb1, char *nb2, char *res)
{
    sub_compute(nb1, nb2, res);
    res = my_revstr(res);
    remov_0(res);
    my_putstr(res);
}