/*
** EPITECH PROJECT, 2019
** my_concat_list.c
** File description:
** my_concat_list
*/
#include "include/mylist.h"
#include<stdlib.h>

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *list;

    list = *begin1;
    while (1 == 1) {
        if (list->next == NULL) {
            list->next = begin2;
            return;
        }
        list = list->next;
    }
}