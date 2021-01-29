/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** redirection_cmd
*/

#include "minishell.h"

int redirection_cmd(char *command, env_t **env_list)
{
    char **cmd = cut_redirection_cmd(command);
    int write_cmd = 0;

    for (int i = 0; command[i]; ++i)
        if (command[i] == '>')
            write_cmd = 1;
    if (write_cmd)
        write_command(command, cmd, env_list);
    else
        read_command(command, cmd, env_list);
    return (IGNORE_EXIT);
}