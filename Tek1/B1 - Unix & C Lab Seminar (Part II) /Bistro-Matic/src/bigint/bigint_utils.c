/*
** EPITECH PROJECT, 2019
** bigint_utils.c
** File description:
** BECAUSE BIGINT ARE SEXY AND VERY BIG
*/

#include "bigint.h"
#include "bistromatic.h"

int nbr_length(long nbr)
{
    int n = 0;

    do {
        nbr /= 10;
        n++;
    } while (nbr);
    return (n);
}

void put_bigint(struct bigint_s* bigint)
{
    int length = (bigint->count);
    int i = (length - 1);
    int j = 0;

    if (bigint->sign)
        put_char('-');
    put_nbr(bigint->numbers[i]);
    while ((--i) >= 0) {
        j = (9 - nbr_length(bigint->numbers[i]));
        for (int k = 0; k < j; k++)
            put_char('0');
        put_nbr(bigint->numbers[i]);
    }
}