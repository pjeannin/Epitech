/*
** EPITECH PROJECT, 2020
** list_to_tab.c
** File description:
** minishell1
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

char **list_to_tab(env_t *env_list)
{
    char **tab = malloc(sizeof(char *) * list_len(env_list) + 1);
    int i = 0;

    env_list = move_beginning(env_list);
    while (env_list) {
        tab[i] = concat_sstr(env_list->name, concat_sstr("=", env_list->value));
        env_list = env_list->next;
        ++i;
    }
    tab[i] = NULL;
    return (tab);
}