/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** allocate memory to a string
*/
#include<stdio.h>

char *my_strdup(char const *str)
{
    char *str2;
    int count = 0;

    str2 = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (str2 == NULL)
        return (NULL);
    for (int i = 1; i < my_strlen(str); ++i) {
        str2[i] = str[i];
        count = i;
    }
    str2[count] = '0';
    return (str2);
}
