/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *str)
{
    char *s = malloc(sizeof(char) * my_strlen(str) + 1);

    if (!s)
        return ((char *)-1);
    my_strcpy(s, str);
    return (s);
}