/*
** EPITECH PROJECT, 2020
** unsetenv_command.c
** File description:
** minishell
*/

#include <stdlib.h>
#include "minishell.h"

void remove_from_env(char *command, env_t **env_list)
{
    char **tab = create_word_list(command, env_list);
    char *name;

    for (int i = 0; tab[i]; ++i) {
        *env_list = move_beginning(*env_list);
        name = tab[i];
        while (comp_str(name, (*env_list)->name) != 0)
            *env_list = (*env_list)->next;
        if ((*env_list)->prev)
            (*env_list)->prev->next = (*env_list)->next;
        else
            (*env_list)->next->prev = NULL;
        if ((*env_list)->next)
            (*env_list)->next->prev = (*env_list)->prev;
        else
            (*env_list)->prev->next = NULL;
    }
}

void unsetenv_command(char *command, env_t **env_list)
{
    char *name;

    if (command[8] == ' ') {
        remove_from_env(&command[9], env_list);
    } else if (command[8] == '\0')
        put_error_str("unsetenv: Too few arguments.\n");
    else
        exe_command(command, env_list);
}