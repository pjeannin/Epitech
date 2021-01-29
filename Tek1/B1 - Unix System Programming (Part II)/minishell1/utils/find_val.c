/*
** EPITECH PROJECT, 2020
** find_val.c
** File description:
** minishell1
*/

#include "minishell.h"

char *find_val(env_t **env_list, char *name)
{
    (*env_list) = move_beginning(*env_list);
    while (comp_str(name, (*env_list)->name))
        (*env_list) = (*env_list)->next;
    return ((*env_list)->value);
}