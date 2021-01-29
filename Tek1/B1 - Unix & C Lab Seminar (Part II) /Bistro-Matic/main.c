/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** BISTRO IS SEXY
*/

#include <stdlib.h>
#include <unistd.h>
#include "bistromatic.h"
#include "evalexpr.h"

int is_double(char c, char *str)
{
    int count = 0;

    while (*str)
        if (*str++ == c)
            ++count;
    return ((count) ? 0 : -1);
}

char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        write(2, "syntax error", 13);
        exit(84);
    }
    expr = malloc(size + 1);
    if (expr == NULL) {
        write(2, "error", 6);
        exit(84);
    }
    if (read(0, expr, size) != size) {
        write(2, "error", 6);
        exit(84);
    }
    expr[size] = 0;
    return (expr);
}

void check_ops(char *ops)
{
    int valid = -1;

    if (str_len(ops) != 7) {
        write(2, "syntax error", 13);
        exit(84);
    }
    for (int i = 0; ops[i]; ++i) {
        valid = is_double(ops[i], ops);
        if (valid == -1) {
            write(2, "syntax error", 13);
            exit(84);
        }
    }
}

void check_base(char *base, char *ops)
{
    int valid = 0;

    if (str_len(base) < 2) {
        write(2, "syntax error", 13);
        exit(84);
    }
    for (int i = 0; base[i]; ++i) {
        valid = is_double(base[i], base);
        if (valid == -1) {
            write(2, "syntax error", 13);
            exit(84);
        }
    }
    valid = 0;
    for (int i = 0; base[i]; ++i) {
        for (int j = 0; ops[j]; ++j)
            valid += (base[i] == ops[j]);
        if (valid != 0) {
            write(2, "syntax error", 13);
            exit(84);
        }
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    int spaces = 0;
    int res;
    char *r;
    char *expr;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        put_str("USAGE\n./calc base operators size_read\n\n");
        put_str("DESCRIPTION\n- base: all the symbols of the base\n");
        put_str("- operators: the symbols for the parentheses and the 5 ");
        put_str("operators\n- size_read: number of characters to be read\n");
        return (84);
    }
    if (ac != 5) {
        put_str("Usage: ./calc base ops\"()+-*/%\" exp_len\n");
        return (84);
    }
    size = my_getnbr(av[3]);
    check_ops(av[2]);
    check_base(av[1], av[2]);
    expr = av[4];
    if ((str_len(expr) - size) != 0) {
        write(2, "syntax error", 13);
        return (84);
    }
    verify_expr(expr, av[1], av[2]);
    for (int i = 0; av[1][i]; ++i)
        spaces += (' ' == av[1][i]);
    for (int i = 0; av[2][i]; ++i)
        spaces += (' ' == av[1][i]);
    if (spaces)
        clean_spaces(expr);
    clean_operations(expr, av[2]);
    res = eval_expr(av[1], av[2], expr);
    put_str(decimal_to_any_base(res, av[1], str_len(av[1])));
    return (0);
}