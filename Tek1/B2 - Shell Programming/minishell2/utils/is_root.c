/*
** EPITECH PROJECT, 2020
** is_root.c
** File description:
** minishell
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int is_root(env_t **env_list)
{
    char *root;
    char *pwd = malloc(sizeof(char) * 100);

    (*env_list) = move_beginning(*env_list);
    while (comp_str("HOME", (*env_list)->name))
        (*env_list) = (*env_list)->next;
    root = (*env_list)->value;
    (*env_list) = move_beginning(*env_list);
    getcwd(pwd, 100);
    return (comp_str(root, pwd));
}