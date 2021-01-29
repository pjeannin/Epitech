/*
** EPITECH PROJECT, 2019
** bistromatic.h
** File description:
** BISTRO IS SEXY
*/

#ifndef BISTROMATIC_H_
#define BISTROMATIC_H_

typedef struct linked_list
{
    long *arg1;
    char op;
    long *arg2;
    char flags;
} linked_list_t ;

char *str_dup(char *src);
void put_char(char c);
void put_nbr(int nbr);
void put_str(char *);
int str_len(char *);
void str_rev(char *);
char *char_from_nbr(int nbr);
int pos_in_base(char c, char *base);
void clean_spaces(char *str);
void clean_operations(char *str, char *ops);
int verify_operations(char *str);
linked_list_t *read_next_token(char **str, char *base, char *ops);
void display_token(linked_list_t *token);
void display_arg(long *arg, int flags);
long eval_arg(long *arg, int flags, char *ops);
long eval_token(linked_list_t *token, char *ops);
void put_nbr(int);
void put_char(char);
int my_getnbr(char *);
void verify_char(char c, char *base, char *ops);
void brack(int *count_brack);
void verify_brack(char *nbr, int i, char *ops, int *count_brack);
void op(char *nbr, int i, char *ops);
void verify_ops(char *nbr, int i, char *ops);
void verify_expr(char *, char *, char *);
char *decimal_to_any_base(int, char *, int);
long any_base_to_decimal(char *, char *, int, int);

#endif
