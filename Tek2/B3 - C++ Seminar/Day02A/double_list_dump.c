/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD02A-pierre.jeannin
** File description:
** double_list_dump
*/

#include <stdio.h>
#include "double_list.h"

void double_list_dump(double_list_t list)
{
    if (list == NULL)
        return;
    while (list->next) {
        printf("%f\n", list->value);
        list = list->next;
    }
    if (list)
        printf("%f\n", list->value);
}