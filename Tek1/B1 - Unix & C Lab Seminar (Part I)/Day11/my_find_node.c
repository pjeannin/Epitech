/*
** EPITECH PROJECT, 2019
** my_find_node.c
** File description:
** my_find_node
*/
#include "include/mylist.h"
#include<stdlib.h>

linked_list_t *my_find_node(linked_list_t const *begin, void const *data_ref,
                            int (*cmp)())
{
    linked_list_t *list;

    list = begin;
    while (list != NULL) {
        if (cmp(data_ref, list->data) == 0)
            return (list);
        list = list->next;
    }
}