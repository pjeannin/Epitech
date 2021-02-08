/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02M-pierre.jeannin
** File description:
** mem_ptr
*/

#include <stdlib.h>
#include <string.h>
#include "mem_ptr.h"

void add_str(const char *str1, const char *str2, char **res)
{
    int index = 0;

    *res = malloc(sizeof(char) * (strlen(str1) + strlen (str2) + 1));
    for (int i = 0; str1[i]; ++i) {
        (*res)[index++] = str1[i];
    }
    for (int i = 0; str2[i]; ++i) {
        (*res)[index++] = str2[i];
    }
    (*res)[index] = '\0';
}

void add_str_struct(str_op_t *str_op)
{
    int index = 0;

    str_op->res = malloc(sizeof(char) * (strlen(str_op->str1)
    + strlen (str_op->str2) + 1));
    for (int i = 0; str_op->str1[i]; ++i) {
        str_op->res[index++] = str_op->str1[i];
    }
    for (int i = 0; str_op->str2[i]; ++i) {
        str_op->res[index++] = str_op->str2[i];
    }
}