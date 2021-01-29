/*
** EPITECH PROJECT, 2020
** glue_sep
** File description:
** take a string and glues it with a sep
*/

#include "../../include/my.h"

char *my_glue_sep(char *path, char *name, char sep)
{
    int i = 0;
    int is_sep = 0;
    char *ret = my_calloc(1, my_strlen(path) + my_strlen(name) + 2);
    int path_len = my_strlen(path);

    if (!(ret))
        return (NULL);
    if (path_len != 0 && path[path_len - 1] == sep)
        is_sep = 1;
    if (path_len == 0)
        is_sep = 1;
    if (path)
        for (; path[i]; ++i)
            ret[i] = path[i];
    if (is_sep == 0)
        ret[i++] = sep;
    for (int j = 0; name[j]; ++j)
        ret[i++] = name[j];
    ret[i] = '\0';
    return (ret);
}
