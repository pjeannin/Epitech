/*
** EPITECH PROJECT, 2020
** move_end.c
** File description:
** minishell
*/

#include "minishell.h"

env_t *move_end(env_t *list)
{
    while (list->next)
        list = list->next;
    return (list);
}