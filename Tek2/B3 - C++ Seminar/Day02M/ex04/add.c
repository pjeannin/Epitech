/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02M-pierre.jeannin
** File description:
** add
*/

#include <stdio.h>
#include "castmania.h"

int normal_add(int a, int b)
{
    return (a + b);
}

int absolute_add(int a, int b)
{
    if (a < 0)
        a *= -1;
    if (b < 0)
        b *= -1;

    return (a + b);
}

void exec_add(addition_t *operation)
{
    int(*operations[2])(int, int) = {normal_add, absolute_add};

    if (operation->add_type < NORMAL || operation->add_type > ABSOLUTE)
        return;
    operation->add_op.res =
    operations[operation->add_type](operation->add_op.a, operation->add_op.b);
}