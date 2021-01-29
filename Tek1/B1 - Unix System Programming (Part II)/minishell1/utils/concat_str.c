/*
** EPITECH PROJECT, 2020
** concat_str.c
** File description:
** my_ls
*/

#include <stdlib.h>
#include "minishell.h"

char *concat_sstr(char *str1, char *str2)
{
    char *str = malloc(sizeof(char) * str_len(str1) + str_len(str2) + 1);
    int p = 0;

    for (int i = 0; i < str_len(str1); ++i)
        str[i] = str1[i];
    for (int i = 0; i < str_len(str2); ++i)
        str[i + str_len(str1) + p] = str2[i];
    str[str_len(str1) + str_len(str2) + p] = '\0';
    return (str);
}

char *concat_str(char *str1, char *str2)
{
    char *str = malloc(sizeof(char) * str_len(str1) + str_len(str2) + 1);
    int p = 0;

    for (int i = 0; i < str_len(str1); ++i)
        str[i] = str1[i];
    if (str1[str_len(str1) - 1] != '/') {
        str[str_len(str1)] = '/';
        ++p;
    }
    for (int i = 0; i < str_len(str2); ++i)
        str[i + str_len(str1) + p] = str2[i];
    str[str_len(str1) + str_len(str2) + p] = '\0';
    return (str);
}