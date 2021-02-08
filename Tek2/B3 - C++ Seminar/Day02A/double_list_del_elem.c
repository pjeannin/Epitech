/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02A-pierre.jeannin
** File description:
** double_list_del_elem
*/

#include <stdlib.h>
#include "double_list.h"

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    double_list_t list = *front_ptr;

    if (!list)
        return (false);
    *front_ptr = list->next;
    free(list);

    return (true);
}

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
        double_list_t list = *front_ptr;

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

bool double_list_del_elem_at_position(double_list_t *front_ptr,
unsigned int position)
{
    double_list_t list = *front_ptr;
    double_list_t tmp;
    int pos = 0;

    if (position - 1 > double_list_get_size(*front_ptr))
        return (false);
    else if (position == 0)
        double_list_del_elem_at_front(front_ptr);
    for (; pos < position - 1; ++pos)
        list = list->next;
    tmp = list->next->next;
    free(list->next);
    list->next = list->next->next;

    return (true);
}