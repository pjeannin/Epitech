/*
** EPITECH PROJECT, 2019
** strlen.c
** File description:
** STRING ARE SEXY
*/

int str_len(char const *str)
{
    int n = 0;

    while (*str++)
        n++;
    return (n);
}