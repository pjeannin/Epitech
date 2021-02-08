/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02A-pierre.jeannin
** File description:
** double_list_get_elem
*/

#include <stdlib.h>
#include "double_list.h"

double double_list_get_elem_at_front(double_list_t list)
{
    if (list == NULL)
        return (0);

    return (list->value);
}

double double_list_get_elem_at_back(double_list_t list)
{
    if (list == NULL)
        return (0);
    while (list->next)
        list = list->next;
    return (list->value);
}

double double_list_get_elem_at_position(double_list_t list,
unsigned int posiiton)
{
    int pos = 0;

    if (list == NULL || posiiton - 1 > double_list_get_size(list))
        return (0);
    for (; pos < posiiton; ++pos)
        list = list->next;

    return (list->value);
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
double value)
{
    if (list == NULL)
        return (NULL);
    for (; list; list = list->next) {
        if (list && list->value == value)
            return (list);
    }

    return (NULL);
}