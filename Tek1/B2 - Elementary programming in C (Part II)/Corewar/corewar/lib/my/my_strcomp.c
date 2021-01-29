/*
** EPITECH PROJECT, 2019
** my_strcompt
** File description:
** my_strcomp
*/

#include "../../include/my.h"

int my_strcomp(char *string, char *testr)
{
    if (*string != *testr)
        return (0);
    if (my_strlen(string) != my_strlen(testr))
        return (0);
    while (*string)
        if (*string++ != *testr++)
            return (0);
    return (1);
}
