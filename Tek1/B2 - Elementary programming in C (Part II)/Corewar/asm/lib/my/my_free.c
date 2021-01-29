/*
** EPITECH PROJECT, 2020
** minishell_no_leak
** File description:
** my_free
*/

#include "../../include/my.h"

void my_free_typoo(void **oo)
{
    for (int e = 0; oo[e] != NULL; e++)
        free(oo[e]);
    free(oo);
}