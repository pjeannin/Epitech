/*
** EPITECH PROJECT, 2019
** my_apply_on_matching_nodes.c
** File description:
** my_apply_on_matching_nodes
*/
#include "include/mylist.h"
#include<stdlib.h>

int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)(), 
                        void const *data_ref, int (*cmp) () )
{
    linked_list_t *list;
    int match;

    list = begin;
    while (list != NULL) {
        if (cmp(data_ref, list->data) == 0)
            f(list->data);
        list = list->next;
    }
}