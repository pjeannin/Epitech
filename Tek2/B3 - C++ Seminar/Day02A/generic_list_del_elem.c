/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02A-pierre.jeannin
** File description:
** list_del_elem
*/

#include <stdlib.h>
#include "generic_list.h"

bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t list = *front_ptr;

    if (!list)
        return (false);
    *front_ptr = list->next;
    free(list);

    return (true);
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    list_t list = *front_ptr;

    if (!list)
        return (false);
    if (!list->next) {
        free(list);
        *front_ptr = NULL;
    }
    while (list->next->next)
        list = list->next;
    free(list->next);
    list->next = NULL;
    return (true);
}

bool list_del_elem_at_position(list_t *front_ptr,
unsigned int position)
{
    list_t list = *front_ptr;
    list_t tmp;
    int pos = 0;

    if (position - 1 > list_get_size(*front_ptr))
        return (false);
    else if (position == 0)
        list_del_elem_at_front(front_ptr);
    for (; pos < position - 1; ++pos)
        list = list->next;
    tmp = list->next->next;
    free(list->next);
    list->next = list->next->next;

    return (true);
}

void list_clear(list_t *front)
{
    list_t list = *front;
    list_t tmp;

    while (list->next) {
        list = tmp;
        list = list->next;
        free(tmp);
    }
    free(list);
    *front = NULL;
}