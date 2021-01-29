/*
** EPITECH PROJECT, 2019
** my_delete_nodes.c
** File description:
** my_delete_nodes
*/
#include "include/mylist.h"
#include<stdlib.h>

int comp(char *s1, char *s2)
{
    int res = 0;
    int i = 0;

    while (s1[i] != '\0' ||  s2[i] != '\0') {
        if (s1[i] > s2[i]) {
            res = 1;
            return (res);
        }
        if (s1[i] < s2[i]) {
            res = -1;
            return (res);
        }
        ++i;
    }
    if (s1[i] != '\0' &&  s2[i] == '\0' || s1[i] == '\0' && s2[i] != '\0')
        res = 0;
    return (res);
}

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *list;
    linked_list_t *delete;

    list = *begin;
    while (list != NULL) {
        if (list->next == NULL)
            return (0);
        delete = list->next;
        if (comp(data_ref, delete->data) == 0) {
            list->next = delete->next;
        }
        if (comp(data_ref, list->data) == 0)
            *begin = list->next;
        list = list->next;
    }
    return (0);
}