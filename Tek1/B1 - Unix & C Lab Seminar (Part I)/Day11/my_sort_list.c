/*
** EPITECH PROJECT, 2019
** my_sort_list.c
** File description:
** my_sort_list
*/
#include "include/mylist.h"
#include<stdlib.h>

int sort(linked_list_t *list, int (*cmp)())
{
    int ok = 0;
    char *l2;

    while (list->next != NULL) {
        if (cmp(list->data, (list->next)->data) == 1) {
            ok =1;
            l2 = list->data;
            list->data = (list->next)->data;
            (list->next)->data = l2;
        }
        list = list->next;
    }
    return (ok);
}


void my_sort_list(linked_list_t **begin, int (*cmp)())
{
    int ok = 1;
    linked_list_t *list;

    list = *begin;
    while (ok != 0) {
        ok = sort(list, cmp);
    }
}