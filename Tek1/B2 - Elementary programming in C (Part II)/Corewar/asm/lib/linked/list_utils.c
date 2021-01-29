/*
** EPITECH PROJECT, 2020
** list_utils
** File description:
** utilitaries for linked list
*/

#include "../../include/my.h"
#include "../../include/list.h"

unsigned int list_len(list_t *list)
{
    unsigned int ret = 0;

    for (; list; list = list->next)
        ++ret;
    return (ret);
}

void list_print(list_t *list)
{
    for (; list; list = list->next) {
        my_putstr(1, list->string);
        write (1, "\n", 1);
    }
}

void list_free(list_t *list)
{
    list_t *tmp;

    while (list) {
        tmp = list->next;
        free_node(list);
        list = tmp;
    }
}
