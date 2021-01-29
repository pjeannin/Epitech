/*
** EPITECH PROJECT, 2020
** clean_cmd.c
** File description:
** minishell1
*/

#include <stdlib.h>
#include "minishell.h"

char *clean_cmd(char *cmd)
{
    char *ret = malloc(sizeof(char) * str_len(cmd) + 1);
    int index = 0;

    for (int i = 0; cmd[i]; ++i) {
        if (cmd[i] == ' ' && cmd[i + 1] == ' ')
            continue;
        else {
            ret[index] = cmd[i];
            ++index;
        }
    }
    ret[index] = '\0';
    return (ret);
}