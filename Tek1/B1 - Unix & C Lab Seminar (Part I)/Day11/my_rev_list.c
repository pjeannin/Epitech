/*
** EPITECH PROJECT, 2019
** my_rev_list.c
** File description:
** my_rev_list
*/
#include "include/mylist.h"
#include<stdlib.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *l1 = NULL;
    linked_list_t *l2;
    linked_list_t *l3;

    l2 = *begin;
    while (l2 != NULL) {
        l3 = l2->next;
        l2->next = l1;
        l1 = l2;
        l2 = l3;
    *begin = l1;
    }
}