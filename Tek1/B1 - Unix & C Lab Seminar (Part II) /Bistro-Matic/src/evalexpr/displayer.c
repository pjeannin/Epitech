/*
** EPITECH PROJECT, 2019
** displayer.c
** File description:
** EVALEXPR IS SEXY
*/

#include "bistromatic.h"

void display_arg(long *arg, int flags)
{
    if (flags)
        display_token((linked_list_t*)arg);
    else
        put_nbr((long)arg);
}

void display_token(linked_list_t *token)
{
    put_char('(');
    display_arg(token->arg1, (token->flags & 1));
    if (token->op) {
        put_char(token->op);
        display_arg(token->arg2, (token->flags & 2));
    }
    put_char(')');
}