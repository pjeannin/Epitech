/*
** EPITECH PROJECT, 2020
** env_command.c
** File description:
** minishell 1
*/

#include "minishell.h"

void env_command(char *command, env_t *env_list)
{
    env_list = move_beginning(env_list);
    if (str_len(command) == 3)
        while (env_list) {
            put_str(env_list->name);
            put_str("=");
            put_str(env_list->value);
            put_str("\n");
            env_list = env_list->next;
        }
    else
        exe_command(command, &env_list);
}