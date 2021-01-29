/*
** EPITECH PROJECT, 2019
** verify_expr.c
** File description:
** YOU MUST PASS
*/

#include<unistd.h>
#include <stdlib.h>

void verify_char(char c, char *base, char *ops)
{
    int valid = 0;

    while (*base)
        if ((*base++) == c)
            return;
    while (*ops)
        if ((*ops++) == c)
            return;
    write(2, "syntax error", 13);
    exit(84);
}

void brack(int *count_brack)
{
    if ((*count_brack) < 0) {
        write(2, "syntax error", 13);
        exit(84);
    }
}

void verify_brack(char *nbr, int i, char *ops, int *count_brack)
{
    if (nbr[i] == ops[0]) {
        ++(*count_brack);
        if (i != 0 && (nbr[i - 1] == ops[1] || (nbr[i - 1] != ops[0] &&
        nbr[i - 1] != ops[2] && nbr[i - 1] != ops[3] && nbr[i - 1] != ops[4]
        && nbr[i - 1] != ops[5] && nbr[i - 1] != ops[6]))) {
            write(2, "syntax error", 13);
            exit(84);
        }
    }
    if (nbr[i] == ops[1]) {
        --(*count_brack);
        if (nbr[i + 1] == ops[0] || (nbr[i + 1] != ops[1] &&
        nbr[i + 1] != ops[2] && nbr[i + 1] != ops[3] && nbr[i + 1] != ops[4]
        && nbr[i + 1] != ops[5] && nbr[i + 1] != ops[6]
        && nbr[i + 1] != '\0')) {
            write(2, "syntax error", 13);
            exit(84);
        }
    }
    brack(count_brack);
}

void op(char *nbr, int i, char *ops)
{
    if (nbr[i + 1] == '\0') {
        write(2, "syntax error", 13);
        exit(84);
    }
    for (int k = 2; ops[k]; ++k) {
        if (ops[k] == nbr[i - 1]) {
            write(2, "syntax error", 13);
            exit(84);
        }
        if (ops[k] == nbr[i + 1]) {
            write(2, "syntax error", 13);
            exit(84);
        }
    }
}

void verify_ops(char *nbr, int i, char *ops)
{
    int valid = 0;

    for (int j = 4; ops [j]; ++j) {
        if (ops[j] == nbr[i]) {
            op(nbr, i, ops);
        }
    }
    valid = 0;
    for (int j = 2; ops [j]; ++j) {
        valid = (ops[j] == nbr[i]);
        if (nbr[i + 1] == '\0' && valid == 1) {
            write(2, "syntax error", 13);
            exit(84);
        }
    }
}