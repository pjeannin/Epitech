/*
** EPITECH PROJECT, 2020
** setenv_command.c
** File description:
** minishell1
*/

#include <stdlib.h>
#include "minishell.h"

void setenv_mid(char *command, env_t **env_list)
{
    while (comp_str(set_name(command), (*env_list)->name) != 0
    && (*env_list)->next)
        *env_list = (*env_list)->next;
    if (comp_str(set_name(command), (*env_list)->name) != 0) {
        (*env_list)->next = malloc(sizeof(env_t));
        (*env_list)->next->prev = *env_list;
        (*env_list) = (*env_list)->next;
    }
    (*env_list)->name = set_name(command);
    if (count_spaces(command) == 2)
        (*env_list)->value = set_val(command);
    else
        (*env_list)->value = "";
}

void setenv_command(char *command, env_t **env_list)
{
    (*env_list) = move_beginning(*env_list);
    if (str_len(command) == str_len("setenv"))
        env_command("env", *env_list);
    else if (count_spaces(command) == 2 || count_spaces(command) == 1) {
        setenv_mid(command, env_list);
    } else
        put_error_str("setenv: Too many arguments.\n");
}