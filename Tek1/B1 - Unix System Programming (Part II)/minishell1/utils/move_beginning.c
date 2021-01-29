/*
** EPITECH PROJECT, 2020
** move_begining.c
** File description:
** minishell1
*/

#include "minishell.h"

env_t *move_beginning(env_t *list)
{
    while (list->prev)
        list = list->prev;
    return (list);
}