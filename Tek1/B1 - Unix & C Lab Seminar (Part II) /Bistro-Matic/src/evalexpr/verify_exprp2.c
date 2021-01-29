/*
** EPITECH PROJECT, 2019
** verify_expr.c
** File description:
** YOU MUST PASS
*/

#include "bistromatic.h"
#include<unistd.h>
#include <stdlib.h>

void verify_expr(char *nbr, char *base, char *ops)
{
    int count_brack = 0;
    int *pcount_brack = &count_brack;

    for (int i = 0; nbr[i]; ++i) {
        verify_char(nbr[i], base, ops);
        verify_brack(nbr, i, ops, pcount_brack);
        verify_ops(nbr, i, ops);
    }
    if (count_brack != 0) {
        write(2, "syntax error", 13);
        exit(84);
    }
}