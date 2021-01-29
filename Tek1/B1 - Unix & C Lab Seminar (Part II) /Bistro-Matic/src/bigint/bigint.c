/*
** EPITECH PROJECT, 2019
** bigint.c
** File description:
** BECAUSE BIGINT ARE SEXY AND VERY BIG
*/

#include <stdlib.h>
#include "bigint.h"

// struct bigint_s *bigint_from_base(const char *str, const char *base, int base_len)
// {
//     struct bigint_s *bigint = bigint_from_nbr(0);
//     int n = 0;
//     int j = 1;

//     while (*(str++));
//     *(str--);
//     *(str--);
//     while (*str) {
//         n += (*str-- & 0xF) * j;
//         j *= 10;
//         if (j == 1000000000) {
//             bigint->nbr = n;
//             bigint->prev = bigint_from_nbr(0);
//             bigint->prev->next = bigint;
//             bigint = bigint->prev;
//             n = 0;
//             j = 1;
//         }
//     }
//     bigint->nbr = n;
//     while (bigint->next)
//         bigint = bigint->next;
//     return (bigint);
// }

struct bigint_s *bigint_from_nbr(long nbr)
{
    struct bigint_s *bigint = malloc(sizeof(struct bigint_s));
    int i = 0;

    bigint->numbers = malloc(sizeof(int) * 4096);
    for (int i = 0; i < 4096; i++)
        bigint->numbers[i] = 0;
    if (nbr < 0) {
        nbr *= -1;
        bigint->sign = 1;
    }
    while (nbr) {
        bigint->numbers[i++] = (nbr % 1000000000);
        nbr /= 1000000000;
    }
    bigint->count = i;
    return (bigint);
}

void free_bigint(struct bigint_s *bigint)
{
    free(bigint->numbers);
    free(bigint);
}

// int main(int argc, char **argv)
// {
//     struct bigint_s *a = bigint_from_nbr(100000);
//     struct bigint_s *b = bigint_from_nbr(2);
//     struct bigint_s *c = bigint_sub(a, b);

//     put_str("a: ");
//     put_bigint(a);
//     put_str("\n");
//     put_str("b: ");
//     put_bigint(b);
//     put_str("\n");
//     put_str("c: ");
//     put_bigint(c);
//     put_str("\n");
//     free_bigint(a);
//     free_bigint(b);
//     free_bigint(c);
//     return (0);
// }