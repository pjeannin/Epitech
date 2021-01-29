/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** str_dup
*/

#include <stdlib.h>
#include "minishell.h"

char *str_dup(char *str)
{
    char *ret = malloc(sizeof(char) * (str_len(str) + 1));

    for (int i = 0; str[i]; ++i)
        ret[i] = str[i];
    ret[str_len(str)] = '\0';
    return (ret);
}