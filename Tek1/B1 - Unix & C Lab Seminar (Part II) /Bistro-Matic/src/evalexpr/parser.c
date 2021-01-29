/*
** EPITECH PROJECT, 2019
** parser.c
** File description:
** EVALEXPR IS SEXY
*/

#include <stdlib.h>
#include "bistromatic.h"

linked_list_t *new_token(void)
{
    linked_list_t *token = (linked_list_t*)malloc(sizeof(struct linked_list));

    token->arg1 = NULL;
    token->arg2 = NULL;
    token->op = 0;
    token->flags = 0;
    return (token);
}

long read_next_nbr(char **str, char *base, char *ops)
{
    char *n;
    char *nbr = *str;
    int sign = 0;
    int nbr_length = 0;

    if (*nbr == ops[3]) {
        ++nbr;
        ++nbr_length;
    }
    while (*nbr != ops[0] && *nbr != ops[1] && *nbr != ops[2] &&
    *nbr != ops[3] && *nbr != ops[4] && *nbr != ops[5] &&
    *nbr != ops[6] && *nbr) {
        ++nbr;
        ++nbr_length;
    }
    n = malloc(sizeof(char) * nbr_length + 1);
    for (int i = 0; i < nbr_length; ++i)
        n[i] = *((*str)++);
    n[nbr_length] = 0;
    return (any_base_to_decimal(n, base, str_len(base), nbr_length));
}

int read_arg(char **str, long **arg, char *base, char *ops)
{
    if (**str == ops[0]) {
        (*str)++;
        *arg = (long*)read_next_token(str, base, ops);
        return (1);
    } else {
        *arg = (long*)read_next_nbr(str, base, ops);
        return (0);
    }
}

void read_priority(linked_list_t* parent, char **str, char *base, char *ops)
{
    linked_list_t *extra;
    linked_list_t *tmp;

    if (**str == ops[4] || **str == ops[5] || **str == ops[6]) {
        extra = new_token();
        extra->arg1 = parent->arg1;
        extra->flags |= (parent->flags & 1) ? (1) : (0);
        extra->op = **str;
        (*str)++;
        if (extra->op == ops[3] && **str != ops[0]) {
            (*str)--;
            extra->op = ops[2];
        }
        extra->flags |= (read_arg(str, &extra->arg2, base, ops)) ? (2) : (0);
        parent->arg1 = (long*)extra;
        parent->flags |= 1;
        read_priority(parent, str, base, ops);
    }
}

void read_other_token (char **str, linked_list_t *list, char *base, char *ops)
{
    linked_list_t *extra;

    while (**str && **str != ops[1]) {
        extra = new_token();
        extra->arg1 = list->arg2;
        if (list->flags & 2)
            extra->flags |= 1;
        read_priority(extra, str, base, ops);
        if (**str == '\0')
            return;
        if (**str == ops[1]) {
            (*str)++;
        }
        extra->op = *(*str)++;
        if (extra->op == ops[3] && **str != ops[0]) {
            (*str)--;
            extra->op = ops[2];
        }
        extra->flags |= (read_arg(str, &extra->arg2, base, ops)) ? (2) : (0);
        list->arg2 = (long*)extra;
        list->flags |= 2;
        list = extra;
    }
}



linked_list_t *read_next_token(char **str, char *base, char *ops)
{
    linked_list_t *list = new_token();
    linked_list_t *origin = list;

    list->flags |= (read_arg(str, &list->arg1, base, ops)) ? (1) : (0);
    if (**str == ops[1]) {
        (*str)++;
        return (list);
    }
    read_priority(list, str, base, ops);
    if (**str == ops[1]) {
        (*str)++;
        return (list);
    }
    list->op = *(*str)++;
    if (list->op == ops[3] && **str != ops[0]) {
        (*str)--;
        list->op = ops[2];
    }
    list->flags |= (read_arg(str, &list->arg2, base, ops)) ? (2) : (0);
    read_other_token(str, list, base, ops);
    if (**str == ops[1])
        (*str)++;
    return (origin);
}
