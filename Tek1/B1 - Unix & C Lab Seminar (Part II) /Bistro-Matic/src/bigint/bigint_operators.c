/*
** EPITECH PROJECT, 2019
** bigint_operators.c
** File description:
** BECAUSE BIGINT ARE SEXY AND VERY BIG
*/

#include "bigint.h"

struct bigint_s *bigint_add(struct bigint_s *a, struct bigint_s *b)
{
    struct bigint_s *c = bigint_from_nbr(0);
    long i = 0;
    long n = 0;
    long r = 0;

    while ((a->numbers[i]) || (b->numbers[i]) || r) {
        n = ((a->numbers[i]) + (b->numbers[i]) + r);
        if (n >= 1000000000) {
            n -= 1000000000;
            r = 1;
        } else
            r = 0;
        c->numbers[i++] = n;
    }
    c->count = i;
    return (c);
}

struct bigint_s *bigint_sub(struct bigint_s *a, struct bigint_s *b)
{
    struct bigint_s *c = bigint_from_nbr(0);
    long i = 0;
    long n = 0;
    long r = 0;

    while ((a->numbers[i]) || (b->numbers[i]) || r) {
        if ((a->numbers[i]) < (b->numbers[i])) {
            c->sign = 1;
            n = ((b->numbers[i]) - (a->numbers[i]) - r);
        } else
            n = ((a->numbers[i]) - (b->numbers[i]) - r);
        if (n < 0) {
            n += 1000000000;
            r = 1;
        } else
            r = 0;
        c->numbers[i++] = n;
    }
    c->count = i;
    return (c);
}

// struct bigint_s *bigint_sub(struct bigint_s *a, struct bigint_s *b)
// {
//     struct bigint_s *c = bigint_from_nbr(0);
//     struct bigint_s *origin = c;
//     long n = 0;
//     long r = 0;

//     while (a || b || r) {
//         n = (bigint_to_nbr_prev(&a) - bigint_to_nbr_prev(&b) - r);
//         if (n < 0) {
//             n += 1000000000;
//             r = 1;
//         } else
//             r = 0;
//         c->nbr = n;
//         if (a || b || r) {
//             c->prev = bigint_from_nbr(0);
//             c->prev->next = c;
//             c = (c->prev);
//         }
//     }
//     return (origin);
// }

// struct bigint_s *bigint_mul(struct bigint_s *a, struct bigint_s *b)
// {
//     struct bigint_s *c = bigint_from_nbr(0);
//     struct bigint_s *comp = bigint_from_nbr(1);
//     struct bigint_s *count = bigint_from_nbr(0);
//     long n = 0;
//     long r = 0;

//     if (bigint_is_sup(a, b))
//         return (bigint_mul(b, a));
//     // while (a || b || r) {
//     //     n = (bigint_to_nbr_prev(&a) - bigint_to_nbr_prev(&b) - r);
//     //     if (n >= 1000000000) {
//     //         r = (n / 1000000000);
//     //         n = (n % 1000000000);
//     //     } else
//     //         r = 0;
//     //     c->nbr = n;
//     //     c->prev = bigint_from_nbr(0);
//     //     c->prev->next = (c->prev);
//     //     c = (c->prev);
//     // }
//     while (bigint_is_strict_sup(a, count)) {
//         c = bigint_add(b, c);
//         count = bigint_add(count, comp);
//     }
//     return (c);
// }

// struct bigint_s *bigint_div(struct bigint_s *a, struct bigint_s *b)
// {
//     struct bigint_s *c = bigint_from_nbr(0);
//     struct bigint_s *d = bigint_from_nbr(0);
//     struct bigint_s *e = bigint_from_nbr(1);
//     struct bigint_s *origin = d;

//     if (bigint_is_inf(a, b)) {
//         free_bigint(c);
//         free_bigint(e);
//         return (d);
//     }
//     while (bigint_is_inf(c, a)) {
//         c = bigint_add(c, b);
//         d = bigint_add(d, e);
//     }
//     free_bigint(c);
//     free_bigint(e);
//     return (d);
// }

// struct bigint_s *bigint_mod(struct bigint_s *a, struct bigint_s *b)
// {
//     struct bigint_s *c = bigint_div(a, b);

//     return (bigint_sub(a, c));
// }