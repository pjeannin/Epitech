/*
** EPITECH PROJECT, 2019
** my_add_in_sorted_list.c
** File description:
** my_add_in_sorted_list
*/
#include "include/mylist.h"
#include<stdlib.h>

void my_add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)())
{
    linked_list_t *element;
    linked_list_t *list;

    list = *begin;
    element  = malloc(sizeof(*element));
    element->data = data;
    while (cmp(data, (list->next)->data) != -1)
        list = list->next;
    element->next = list->next;
    list->next = element;
}