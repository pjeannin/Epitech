/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** init_input_list
*/

#include "get_input.h"

input_list_t *init_input_list(void)
{
    input_list_t *list = malloc(sizeof(input_list_t));

    if (!list)
        return ((input_list_t *) NULL);
    list->prev = NULL;
    list->next = NULL;
    list->line = NULL;
    return (list);
}