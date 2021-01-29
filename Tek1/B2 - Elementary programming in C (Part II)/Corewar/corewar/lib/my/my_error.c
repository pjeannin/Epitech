/*
** EPITECH PROJECT, 2020
** 109titration_2019
** File description:
** my_error
*/

#include "../../include/my.h"

int error(int error, char *str)
{
    write(2, str, my_strlen(str));
    return (error);
}

void *errorn(char *str)
{
    write(2, str, my_strlen(str));
    return (NULL);
}