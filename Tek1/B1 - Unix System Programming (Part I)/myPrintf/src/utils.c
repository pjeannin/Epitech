/*
** EPITECH PROJECT, 2019
** put.c
** File description:
** PUT EVERYTHING INTO *EVERYTHING*
*/

#include <stdlib.h>
#include <unistd.h>

int str_len(char *str)
{
    int res = 0;

    while (*str++)
        res += 1;
    return (res);
}

void rev_str(char *str)
{
    int i = 0;
    int j = (str_len(str) - 1);
    char tmp;

    while (i < j) {
        tmp = str[i];
        str[i++] = str[j];
        str[j--] = tmp;
    }
}

int my_getnbr(char **str)
{
    int n = 0;
    int sign = 0;

    if (**str == '-') {
        sign = 1;
        (*str)++;
    }
    while ((**str >= '0') && (**str <= '9')) {
        n *= 10;
        n += (**str & 0xF);
        (*str)++;
    }
    return (sign) ? (-n) : (n);
}

int __put_nbr(long long nbr, int len)
{
    char c = ((nbr % 10) | 48);

    nbr /= 10;
    if (nbr) {
        ++len;
        len = __put_nbr(nbr, len);
    }
    write(1, &c, 1);
    return (len);
}

int put_nbr(long long nbr)
{
    int len = 0;

    if (nbr < 0) {
        write(1, "-", 1);
        nbr *= -1;
        ++len;
    }
    len = __put_nbr(nbr, len);
    return (len);
}