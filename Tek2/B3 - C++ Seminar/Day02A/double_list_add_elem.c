/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02A-pierre.jeannin
** File description:
** double_list_add_elem
*/

#include <stdlib.h>
#include "double_list.h"

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    double_list_t new_node = malloc(sizeof(doublelist_node_t));

    if (!new_node)
        return (false);
    new_node->value = elem;
    new_node->next = (*front_ptr);
    *front_ptr = new_node;

    return (true);
}

bool double_list_add_elem_at_back(double_list_t *front_ptr , double elem)
{
    double_list_t list = *front_ptr;
    double_list_t new_node = malloc(sizeof(doublelist_node_t));

    if (!new_node)
        return (false);
    new_node->value = elem;
    new_node->next = NULL;
    if (*front_ptr == NULL) {
        *front_ptr = new_node;
        return (true);
    }
    while (list->next)
        list = list->next;
    list->next = new_node;

    return (true);
}

bool double_list_add_elem_at_position(double_list_t *front_ptr , double elem,
unsigned int position)
{
    double_list_t list = *front_ptr;
    double_list_t new_node;
    int pos = 0;

    if (double_list_get_size(*front_ptr) < position)
        return (false);
    else if (position == 0)
        return (double_list_add_elem_at_front(front_ptr, elem));
    new_node = malloc(sizeof(doublelist_node_t));
    if (!new_node)
        return (false);
    new_node->value = elem;
    for (; pos < position - 1; ++pos)
        list = list->next;
    new_node->next = list->next;
    list->next = new_node;

    return (true);
}