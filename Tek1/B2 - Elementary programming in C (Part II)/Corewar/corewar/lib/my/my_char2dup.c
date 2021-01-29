/*
** EPITECH PROJECT, 2020
** my_char2dup
** File description:
** duplicates a char **
*/

#include "../../include/my.h"

char **my_char2dup(char **array)
{
    int len = my_char2len(array);
    char **ret = malloc(sizeof(char *) * (len + 1));
    char **tmp = ret;

    if (ret == NULL)
        return (NULL);
    while (*array) {
        *tmp = my_strdup(*array++);
        if (*tmp == NULL) {
            multi_free("2", ret);
            return (NULL);
        }
        ++tmp;
    }
    *tmp = NULL;
    return (ret);
}
