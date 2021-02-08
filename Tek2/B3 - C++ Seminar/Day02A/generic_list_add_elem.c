/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02A-pierre.jeannin
** File description:
** list_add_elem
*/

#include <stdlib.h>
#include "generic_list.h"

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t new_node = malloc(sizeof(node_t));

    if (!new_node)
        return (false);
    new_node->value = elem;
    new_node->next = (*front_ptr);
    *front_ptr = new_node;

    return (true);
}

bool list_add_elem_at_back(list_t *front_ptr , void *elem)
{
    list_t list = *front_ptr;
    list_t new_node = malloc(sizeof(node_t));

    if (!new_node)
        return (false);
    new_node->value = elem;
    new_node->next = NULL;
    if (list == NULL) {
        *front_ptr = new_node;
        return (true);
    }
    while (list->next)
        list = list->next;
    list->next = new_node;

    return (true);
}

bool list_add_elem_at_position(list_t *front_ptr , void *elem,
unsigned int position)
{
    list_t list = *front_ptr;
    list_t new_node;
    int pos = 0;

    if (list_get_size(*front_ptr) < position)
        return (false);
    else if (position == 0)
        return (list_add_elem_at_front(front_ptr, elem));
    new_node = malloc(sizeof(node_t));
    if (!new_node)
        return (false);
    new_node->value = elem;
    for (; pos < position - 1; ++pos)
        list = list->next;
    new_node->next = list->next;
    list->next = new_node;

    return (true);
}