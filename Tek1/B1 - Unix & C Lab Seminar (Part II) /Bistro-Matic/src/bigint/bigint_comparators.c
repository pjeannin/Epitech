/*
** EPITECH PROJECT, 2019
** bigint_comparators.c
** File description:
** BECAUSE BIGINT ARE SEXY AND VERY BIG
*/

#include "bigint.h"

int bigint_is_equal(struct bigint_s *a, struct bigint_s *b)
{
    if ((a->sign) != (b->sign))
        return (0);
    if ((a->count) != (b->count))
        return (0);
    for (int i = 0; i < (a->count); i++)
        if ((a->numbers[i]) != (b->numbers[i]))
            return (0);
    return (1);
}

int bigint_is_sup(struct bigint_s *a, struct bigint_s *b)
{
    if ((a->sign) != (b->sign))
        return (a->sign == 0);
    if ((a->count) < (b->count))
        return (0);
    if ((a->count) > (b->count))
        return (1);
    for (int i = 0; i < (a->count); i++)
        if ((a->numbers[i]) < (b->numbers[i]))
            return (0);
    return (1);
}

int bigint_is_strict_sup(struct bigint_s *a, struct bigint_s *b)
{
    if ((a->sign) != (b->sign))
        return (a->sign == 0);
    if ((a->count) < (b->count))
        return (0);
    if ((a->count) > (b->count))
        return (1);
    for (int i = 0; i < (a->count); i++)
        if ((a->numbers[i]) <= (b->numbers[i]))
            return (0);
    return (1);
}

int bigint_is_inf(struct bigint_s *a, struct bigint_s *b)
{
    if ((a->sign) != (b->sign))
        return (a->sign == 0);
    if ((a->count) < (b->count))
        return (1);
    if ((a->count) > (b->count))
        return (0);
    for (int i = 0; i < (a->count); i++)
        if ((a->numbers[i]) > (b->numbers[i]))
            return (0);
    return (1);
}

int bigint_is_strict_inf(struct bigint_s *a, struct bigint_s *b)
{
    if ((a->sign) != (b->sign))
        return (a->sign == 0);
    if ((a->count) < (b->count))
        return (1);
    if ((a->count) > (b->count))
        return (0);
    for (int i = 0; i < (a->count); i++)
        if ((a->numbers[i]) >= (b->numbers[i]))
            return (0);
    return (1);
}