/*
** EPITECH PROJECT, 2020
** free_list.c
** File description:
** minishell 1
*/

#include <stdlib.h>
#include "minishell.h"

void free_list(env_t *list)
{
    list = move_beginning(list);

    while (list->next) {
        free(list->name);
        free(list->value);
        list = list->next;
        free(list->prev);
    }
    free(list);
}