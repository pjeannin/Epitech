/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** cut_redirection_cmd
*/

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"

char ** cut_redirection_cmd(char *command)
{
    char **cmd = malloc(sizeof(char *) * 2);
    int i = 0;
    int index = 0;

    cmd[0] = malloc(sizeof(char) * str_len(command));
    cmd[1] = malloc(sizeof(char) * str_len(command));
    for (; command[i + 1] && command[i + 1] != '<'
    && command[i + 1] != '>'; ++i)
        cmd[0][i] = command[i];
    cmd[0][i++] = '\0';
    for (; command[i] != ' '; ++i);
    ++i;
    for (; command[i]; ++i)
        cmd[1][index++] = command[i];
    cmd[1][index] = '\0';
    return (cmd);
}