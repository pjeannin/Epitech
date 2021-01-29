/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** EVALEXPR IS SEXY
*/

#include "evalexpr.h"
#include "lib.h"
#include <stdlib.h>

long eval_arg(long *arg, int flags)
{
    if (flags)
        return (long)eval_token((linked_list_t*)arg);
    else
        return (long)arg;
}

long eval_token(linked_list_t *token)
{
    long arg1 = eval_arg(token->arg1, token->flags & 1);
    long arg2 = eval_arg(token->arg2, token->flags & 2);

    switch (token->op) {
        case '+':
            free(token);
            return (arg1 + arg2);
        case '-':
            free(token);
            return (arg1 - arg2);
        case '*':
            free(token);
            return (arg1 * arg2);
        case '/':
            free(token);
            return (arg1 / arg2);
        case '%':
            free(token);
            return (arg1 % arg2);
        default:
            free(token);
            return (arg1);
    }
}

int eval_expr(char const *str)
{
    linked_list_t *token;
    char *expr = str_dup(str);
    char *origin = expr;
    int result = 0;

    clean_spaces(expr);
    clean_operations(expr);
    token = read_next_token(&expr);
    result = eval_token(token);
    free(origin);
    return (result);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        put_nbr(eval_expr(av[1]));
        put_char('\n');
        return (0);
    }
    return (84);
}