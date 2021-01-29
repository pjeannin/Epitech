/*
** EPITECH PROJECT, 2019
** Day07
** File description:
** strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i;
    int j;

    i = my_strlen(dest);
    j = 0;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
