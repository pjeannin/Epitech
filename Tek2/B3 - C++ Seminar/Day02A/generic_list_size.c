/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02A-pierre.jeannin
** File description:
** double_list_size
*/

#include <stdlib.h>
#include "generic_list.h"

unsigned int list_get_size(list_t list)
{
    int size = 1;

    if (!list)
        return (0);
    for (; list->next; ++size)
        list = list->next;

    return (size);
}

bool list_is_empty(list_t list)
{
    return (list == NULL ? true : false);
}