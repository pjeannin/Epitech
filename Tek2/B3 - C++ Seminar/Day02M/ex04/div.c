/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02M-pierre.jeannin
** File description:
** div
*/

#include "castmania.h"

int integer_div(int a, int b)
{
    if (!b)
        return (0);
    return (a / b);
}

float decimale_div(int a, int b)
{
    if (!b)
        return (0);
    return ((float)a / (float)b);
}

void exec_div(division_t *operation)
{
    switch (operation->div_type)
    {
    case INTEGER:
        ((integer_op_t *)operation->div_op)->res = integer_div(
        ((integer_op_t *)operation->div_op)->a,
        ((integer_op_t *)operation->div_op)->b);
        break;
    case DECIMALE:
        ((decimale_op_t *)operation->div_op)->res = decimale_div(
        ((decimale_op_t *)operation->div_op)->a,
        ((decimale_op_t *)operation->div_op)->b);
        break;
    default:
        break;
    }
}