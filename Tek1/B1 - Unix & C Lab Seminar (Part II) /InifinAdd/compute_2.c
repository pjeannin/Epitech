/*
** EPITECH PROJECT, 2019
** compute_2.c
** File description:
** inf add
*/

int compute_special(char *res, char *nb, int r, int i)
{
    res[i] = nb[i] + r;
    if (res[i] > 57) {
        res[i] -= 10;
        r = 1;
    }
    else
        r = 0;
    return (r);
}