/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** str_comp
*/

#include "../include/generator.h"

int str_comp(char *str1, char *str2)
{
    if (str_len(str1) != str_len(str2))
        return (1);
    for (int i = 0; str1[i] && str2[i]; ++i)
        if (str1[i] != str2[i])
            return (1);
    return (0);
}