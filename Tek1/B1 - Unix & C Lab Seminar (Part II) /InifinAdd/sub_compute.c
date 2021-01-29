/*
** EPITECH PROJECT, 2019
** sub_compute.c
** File description:
** inf add
*/

void sub_compute(char *nb1, char *nb2, char *res)
{
    int i = 0;
    int r = 0;
    int c;

    while (nb1[i] && nb2[i] != '-') {
        c = (nb1[i] - 48) - (nb2[i] - 48 + r);
        if (c < 0) {
            c = (nb1[i] - 38) - (nb2[i] - 48 + r);
            r = 1;
        }
        else
            r = 0;
        res[i] = c + 48;
        ++i;
    }
    while (nb1[i] != '\0') {
        res[i] = nb1[i] - r;
        r = 0;
        ++i;
    }
}