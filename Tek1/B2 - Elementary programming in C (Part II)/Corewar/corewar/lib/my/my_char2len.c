/*
** EPITECH PROJECT, 2020
** my_char2len
** File description:
** char2len
*/

#include <stdlib.h>

int my_char2len(char **char2)
{
    int i = 0;

    if (char2 == NULL)
        return (0);
    while (char2[i])
        ++i;
    return (i);
}
