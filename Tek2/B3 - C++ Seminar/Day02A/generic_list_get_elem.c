/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02A-pierre.jeannin
** File description:
** list_get_elem
*/

#include <stdlib.h>
#include "generic_list.h"

void *list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return (0);

    return (list->value);
}

void *list_get_elem_at_back(list_t list)
{
    if (list == NULL)
        return (0);
    while (list->next)
        list = list->next;
    return (list->value);
}

void *list_get_elem_at_position(list_t list,
unsigned int posiiton)
{
    int pos = 0;

    if (list == NULL || posiiton - 1 > list_get_size(list))
        return (0);
    for (; pos < posiiton; ++pos)
        list = list->next;

    return (list->value);
}

node_t *list_get_first_node_with_value(list_t list, void *value,
value_comparator_t val_comp)
{
    if (list == NULL)
        return (NULL);
    for (; list; list = list->next) {
        if (list && val_comp(list->value, value))
            return (list);
    }

    return (NULL);
}