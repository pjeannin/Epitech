/*
** EPITECH PROJECT, 2020
** my_slice
** File description:
** slices a string
*/

#include "../../include/my.h"

static char *slicer(char *str, int slice)
{
    char *ret = malloc(sizeof(char) * slice + 1);
    char *tmp = ret;

    if (ret == NULL)
        return (NULL);
    for (int i = 0; i < slice; ++i) {
        *tmp = *str++;
        ++tmp;
    }
    *tmp = '\0';
    return (ret);
}

char *my_slice(char *str, int start, int end)
{
    int len = my_strlen(str);

    if (str == NULL || start < 0 || start >= len)
        return (NULL);
    if (end == 0)
        return (my_strdup(str + start));
    if (end <= start)
        return (NULL);
    end = end - start;
    len = my_strlen(str + start);
    if (len > end)
        len = end;
    return (slicer(str, len));
}
