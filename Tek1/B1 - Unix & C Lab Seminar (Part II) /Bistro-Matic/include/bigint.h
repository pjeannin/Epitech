/*
** EPITECH PROJECT, 2019
** bigint.h
** File description:
** BECAUSE BIGINT ARE SEXY AND VERY BIG
*/

#ifndef BIGINT_H
#define BIGINT_H

struct bigint_s
{
    int sign;
    int *numbers;
    int count;
};

struct bigint_s *bigint_from_base(const char *str, const char *base, int base_len);
struct bigint_s *bigint_from_nbr(long nbr);
void free_bigint(struct bigint_s *bigint);

int bigint_is_equal(struct bigint_s *a, struct bigint_s *b);
int bigint_is_sup(struct bigint_s *a, struct bigint_s *b);
int bigint_is_strict_sup(struct bigint_s *a, struct bigint_s *b);
int bigint_is_inf(struct bigint_s *a, struct bigint_s *b);
int bigint_is_strict_inf(struct bigint_s *a, struct bigint_s *b);

struct bigint_s *bigint_add(struct bigint_s *a, struct bigint_s *b);
struct bigint_s *bigint_sub(struct bigint_s *a, struct bigint_s *b);
struct bigint_s *bigint_mul(struct bigint_s *a, struct bigint_s *b);
struct bigint_s *bigint_div(struct bigint_s *a, struct bigint_s *b);
struct bigint_s *bigint_mod(struct bigint_s *a, struct bigint_s *b);

void put_bigint(struct bigint_s *bigint);

#endif