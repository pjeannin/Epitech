/*
** EPITECH PROJECT, 2019
** Day07
** File description:
** strncat
*/

#include "my.h"
char *my_strncat(char *dest, char const *src, int nb)
{
    int i;
    int len;

    len = my_strlen(dest);
    i = 0;
    while (i < nb && src[i]) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}
