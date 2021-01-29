/*
** EPITECH PROJECT, 2020
** exit_command.c
** File description:
** minishell1
*/

#include <stdlib.h>
#include "minishell.h"

int check_num(char *command)
{
    if (command[5] != '-' && (command[5] < '0' || command[5] > '9')) {
        put_error_str("exit: Badly formed number.\n");
        return (1);
    }
    for (int i = 6; command[i]; ++i)
        if (command[i] < '0' || command[i] > '9') {
            put_error_str("exit: Badly formed number.\n");
            return (1);
        }
    return (0);
}

int exit_command(char *command, env_t **env_list)
{
    if ((command[4] != ' ' && command[4] != '\0')) {
        exe_command(command, env_list);
        return (IGNORE_EXIT);
    } else if (count_spaces(command) > 1) {
        put_error_str("exit: Expression Syntax.\n");
        return (IGNORE_EXIT);
    } else
        if (count_spaces(command) == 1 && check_num(command))
            return (IGNORE_EXIT);
    put_str("exit\n");
    return (my_getnbr(&command[5]) % 256);
}