/*
** EPITECH PROJECT, 2019
** my_apply_on_nods.c
** File description:
** my_apply_on_nodes
*/
#include "include/mylist.h"
#include<stdlib.h>

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    linked_list_t *list;

    list = begin;
    while (list != NULL) {
        f(list->data);
        list = list->next;
    }
}