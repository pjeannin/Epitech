/*
** EPITECH PROJECT, 2019
** isnum.c
** File description:
** isnum
*/

int isnum (char c)
{
    if (c >= 48  && c <= 57)
        return (0);
    else
        return (1);
}