/*
** EPITECH PROJECT, 2019
** evalexpr.h
** File description:
** EVALEXPR IS SEXY
*/

#ifndef EVALEXPR_H_
#define EVALEXPR_H_

typedef struct linked_list
{
    long *arg1;
    char op;
    long *arg2;
    char flags;
} linked_list_t ;

void clean_spaces(char *str);
void clean_operations(char *str);
int verify_operations(char *str);
linked_list_t *read_next_token(char **str);
void display_token(linked_list_t *token);
void display_arg(long *arg, int flags);
long eval_arg(long *arg, int flags);
long eval_token(linked_list_t *token);
void put_nbr(int);
void put_char(char);

#endif