/*
** EPITECH PROJECT, 2019
** comput_1.c
** File description:
** inf add
*/

int compute_add(char *nb1, char *nb2, int r, int i, char *res)
{
    int c;

    c = (nb1[i] - 48) + (nb2[i] - 48) + r;
    if (c > 9) {
        c -= 10;
        r = 1;
    }
    else
        r = 0;
    res[i] = c + 48;
    return (r);
}