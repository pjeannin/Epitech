/*
** EPITECH PROJECT, 2020
** list_len.c
** File description:
** minishell1
*/

#include "minishell.h"

int list_len(env_t *list)
{
    int len = 0;

    list = move_beginning(list);
    while (list) {
        list = list->next;
        ++len;
    }
    return (len);
}