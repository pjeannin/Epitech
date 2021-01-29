/*
** EPITECH PROJECT, 2020
** count_spaces.c
** File description:
** minishell 1
*/

int count_spaces(char *str)
{
    int spaces = 0;

    while (*str++)
        if (*str == ' ')
            ++spaces;
    return (spaces);
}