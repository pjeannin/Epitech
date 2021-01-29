/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** duplicates a string
*/

#include "../../include/my.h"

char *my_strdup(char *str)
{
    char *ret;
    char *tmp;

    if (!(str))
        return (NULL);
    ret = malloc(my_strlen(str) + 1);
    tmp = ret;
    if (ret == NULL)
        return (NULL);
    while (*str) {
        *tmp = *str++;
        ++tmp;
    }
    *tmp = '\0';
    return (ret);
}

char *my_strndup(char *str, int n)
{
    char *ret;
    char *tmp;
    int i = 0;

    if (!(str))
        return (NULL);
    ret = malloc(n + 1);
    tmp = ret;
    if (ret == NULL)
        return (NULL);
    while (*str && i++ < n) {
        *tmp = *str++;
        ++tmp;
    }
    *tmp = '\0';
    return (ret);
}

char *my_strdup_f(char *str)
{
    char *ret = my_strdup(str);

    freeif(str);
    return (ret);
}

char *my_strndup_f(char *str, int n)
{
    char *ret = my_strndup(str, n);

    freeif(str);
    return (ret);
}