/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** EVALEXPR IS SEXY
*/

#include <stdlib.h>
#include "bistromatic.h"

long eval_arg(long *arg, int flags, char *ops)
{
    if (flags)
        return ((long)eval_token((linked_list_t*)arg, ops));
    else
        return ((long)arg);
}

long eval_token(linked_list_t *token, char *ops)
{
    int arg1 = eval_arg(token->arg1, token->flags & 1, ops);
    int arg2 = eval_arg(token->arg2, token->flags & 2, ops);
    int n = arg1;

    if ((token->op) == ops[2])
        n = (arg1 + arg2);
    else if ((token->op) == ops[3])
        n = (arg1 - arg2);
    else if ((token->op) == ops[4])
        n = (arg1 * arg2);
    else if ((token->op) == ops[5])
        n = (arg1 / arg2);
    else if ((token->op) == ops[6])
        n = (arg1 % arg2);
    free(token);
    return (n);
}

int eval_expr(char *base, char *ops, char *expr)
{
    linked_list_t *token;
    int result = 0;

    token = read_next_token(&expr, base, ops);
    put_str(expr);
    result = eval_token(token, ops);
    put_str(expr);
    return (result);
}