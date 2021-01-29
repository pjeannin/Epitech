/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** multiple_cmd
*/

#include "minishell.h"

int count_sep(char *command)
{
    int sep = 1;

    for (int i = 0; command[i]; ++i)
        if (command[i] == ';')
            ++sep;
    return (sep);
}

void multiple_cmd(char *command, env_t **env_list)
{
    char **cmd = cut_cmd(command, ';');
    int nb_sep = count_sep(command);

    for (int i = 0; i < nb_sep; ++i)
        get_command(cmd[i], env_list);
}