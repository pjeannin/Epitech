/*
** EPITECH PROJECT, 2020
** get_command;c
** File description:
** minishell1
*/

#include "minishell.h"

void get_command_end(char *command, env_t **env_list)
{
    if (command[0] == 's' && command[1] == 'e' && command[2] == 't'
        && command[3] == 'e' && command[4] == 'n' && command[5]== 'v')
            setenv_command(command, env_list);
    else if (command[0] == 'u' && command[1] == 'n' && command[2] == 's'
        && command[3] == 'e' && command[4] == 't' && command[5]== 'e'
        && command[6] == 'n' && command[7] == 'v')
        unsetenv_command(command, env_list);
    else
        exe_command(command, env_list);
}

int get_command_mid_mid(char *command, env_t **env_list)
{
    int ret = -1;

    if (command[0] == 'e' && command[1] == 'x' && command[2] == 'i'
        && command[3] == 't') {
        ret = exit_command(command, env_list);
        if (ret != IGNORE_EXIT)
            return (ret);
        }
    else
        get_command_end(command, env_list);
    return (IGNORE_EXIT);
}

int get_command_mid(char *command, env_t **env_list)
{
    if (command[0] == 'c' && command[1] == 'd')
        cd_command(command, env_list);
    else if (command[0] == 'e' && command[1] == 'n' && command[2] == 'v')
        env_command(command, *env_list);
    else
        return (get_command_mid_mid(command, env_list));
    return (IGNORE_EXIT);
}

int get_command_next(char *command, env_t **env_list, int redirect)
{
    int ret = IGNORE_EXIT;

    if (redirect)
        return (redirection_cmd(command, env_list));
    else
        ret = get_command_mid(command, env_list);
    return (ret);
}

int get_command(char *command, env_t **env_list)
{
    int pipe = 0;
    int redirect = 0;
    int multiple = 0;
    int ret = IGNORE_EXIT;

    get_specific_command(command, &pipe, &redirect, &multiple);
    if (multiple)
        multiple_cmd(command, env_list);
    else if (pipe)
        return (pipe_cmd(command, env_list));
    else
        ret = get_command_next(command, env_list, redirect);
    return (ret);
}