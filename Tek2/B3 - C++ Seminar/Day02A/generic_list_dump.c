/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02A-pierre.jeannin
** File description:
** double_list_dump
*/

#include <stdio.h>
#include "generic_list.h"

void list_dump(list_t list, value_displayer_t val_disp)
{
    if (list == NULL)
        return;
    for (; list->next; list = list->next)
        val_disp(list->value);
    if (list)
        val_disp(list->value);
}