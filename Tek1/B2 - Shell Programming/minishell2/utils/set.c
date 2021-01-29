/*
** EPITECH PROJECT, 2020
** set.c
** File description:
** minishell1
*/

#include <stdlib.h>
#include "minishell.h"

char *set_name(char *command)
{
    int i = 0;
    int index = 0;
    char *ret = malloc(sizeof(char) * str_len(command));

    for (; command[i] != ' '; ++i);
    ++i;
    for (; command[i] != ' ' && command[i] != '\0'; ++i) {
        ret[index] = command[i];
        ++index;
    }
    ret[index] = '\0';
    return (ret);
}

char *set_val(char *command)
{
    int i = 0;
    int index = 0;
    char *ret = malloc(sizeof(char) * str_len(command));

    for (; command[i] != ' '; ++i);
    ++i;
    for (; command[i] != ' '; ++i);
    ++i;
    for (; command[i]; ++i) {
        ret[index] = command[i];
        ++index;
    }
    ret[index] = '\0';
    return (ret);
}