/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** find_list_len
*/

#include "minishell.h"

int find_list_len(read_t *list)
{
    int len = 1;

    for (; list->prev; list = list->prev);
    for (; list->next; list = list->next)
        ++len;
    return (len);
}