/*
** EPITECH PROJECT, 2019
** my_params_to_list.c
** File description:
** my_params_to_list
*/
#include "include/mylist.h"
#include<stdlib.h>

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    struct linked_list *list = NULL;
    struct linked_list *element;

    for (int i = 0; i < ac; ++i) {
        element = malloc(sizeof(*element));
        element->data = av[i];
        element->next = list;
        list = element;
    }
    return (list);
}