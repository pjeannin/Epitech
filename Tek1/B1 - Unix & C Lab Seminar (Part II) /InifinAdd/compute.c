/*
** EPITECH PROJECT, 2019
** compute.c
** File description:
** inf add
*/

int compute_add(char *, char *, int, int, char *);
int compute_special(char *, char *, int, int);

void compute(char *nb1, char *nb2, int r, char *res)
{
    char *nb;
    int i = 0;

    while (nb1[i] && nb2[i]) {
        r = compute_add(nb1, nb2, r, i, res);
        ++i;
    }
    if (nb1[i])
        nb = nb1;
    else
        nb = nb2;
    while (nb[i]) {
        r = compute_special(res, nb, r, i);
        ++i;
    }
    if (r == 1) {
        res[i] = 49;
    }
}