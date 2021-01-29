/*
** EPITECH PROJECT, 2020
** concat_str.c
** File description:
** my_ls
*/

#include "my_defender.h"

char *concat_str(char *str1, char *str2)
{
    char *str = malloc(sizeof(char) * str_len(str1) + str_len(str2) + 1);
    int i = 0;

    if (str == NULL)
        return (NULL);
    for (int j = 0; str1[j]; ++j)
        str[i++] = str1[j];
    for (int j = 0; str2[j]; ++j)
        str[i++] = str2[j];
    str[i] = '\0';
    return (str);
}