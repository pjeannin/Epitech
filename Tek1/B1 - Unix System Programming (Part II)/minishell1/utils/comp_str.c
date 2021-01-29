/*
** EPITECH PROJECT, 2020
** comp_str.c
** File description:
** minishell
*/

#include "minishell.h"

int comp_str(char *str1, char *str2)
{
    if (str_len(str1) != str_len(str2))
        return (-1);
    for (int i = 0; str1[i] && str2[i]; ++i)
        if (str1[i] != str2[i])
            return (-1);
    return (0);
}