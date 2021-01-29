/*
** EPITECH PROJECT, 2019
** parser.c
** File description:
** EVALEXPR IS SEXY
*/

#include "evalexpr.h"
#include <stdlib.h>

linked_list_t *new_token(void)
{
    linked_list_t *token = (linked_list_t*)malloc(sizeof(struct linked_list));

    token->arg1 = NULL;
    token->arg2 = NULL;
    token->op = 0;
    token->flags = 0;
    return (token);
}

long read_next_nbr(char **str)
{
    long n = 0;
    int sign = 0;

    if (**str == '-') {
        sign = 1;
        (*str)++;
    }
    while ((**str >= '0') && (**str <= '9')) {
        n *= 10;
        n += (**str & 0xF);
        (*str)++;
    }
    return (sign) ? (-n) : (n);
}

int read_next_arg(char **str, long **arg)
{
    if (**str == '(') {
        (*str)++;
        *arg = (long*)read_next_token(str);
        return (1);
    } else {
        *arg = (long*)read_next_nbr(str);
        return (0);
    }
}

void read_priority_token(linked_list_t* parent, char **str)
{
    linked_list_t *extra;
    linked_list_t *tmp;

    if (**str == '*' || **str == '/' || **str == '%') {
        extra = new_token();
        extra->arg1 = parent->arg1;
        extra->flags |= (parent->flags & 1) ? (1) : (0);
        extra->op = *(*str)++;
        if (extra->op == '-' && **str != '(') {
            (*str)--;
            extra->op = '+';
        }
        extra->flags |= (read_next_arg(str, &extra->arg2)) ? (2) : (0);
        parent->arg1 = (long*)extra;
        parent->flags |= 1;
        read_priority_token(parent, str);
    }
}

void read_other_token (char **str, linked_list_t *list)
{
    linked_list_t *extra;

    while (**str && **str != ')') {
        extra = new_token();
        extra->arg1 = list->arg2;
        if (list->flags & 2)
            extra->flags |= 1;
        read_priority_token(extra, str);
        if (**str == ')') {
            (*str)++;
        } else {
            extra->op = *(*str)++;
            if (extra->op == '-' && **str != '(') {
                (*str)--;
                extra->op = '+';
            }
            extra->flags |= (read_next_arg(str, &extra->arg2)) ? (2) : (0);
        }
        list->arg2 = (long*)extra;
        list->flags |= 2;
        list = extra;
    }
}

linked_list_t *read_next_token(char **str)
{
    linked_list_t *list = new_token();
    linked_list_t *origin = list;

    list->flags |= (read_next_arg(str, &list->arg1)) ? (1) : (0);
    if (**str == ')') {
        (*str)++;
        return (list);
    }
    read_priority_token(list, str);
    if (**str == ')') {
        (*str)++;
        return (list);
    }
    list->op = *(*str)++;
    if (list->op == '-' && **str != '(') {
        (*str)--;
        list->op = '+';
    }
    list->flags |= (read_next_arg(str, &list->arg2)) ? (2) : (0);
    read_other_token(str, list);
    if (**str == ')')
        (*str)++;
    return (origin);
}