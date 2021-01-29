/*
** EPITECH PROJECT, 2019
** arg_in_linkedlist.c
** File description:
** pushswap
*/

#include "pushswap.h"
#include <unistd.h>
#include <stdlib.h>

linked_list_t *create_linkedlist(void)
{
    linked_list_t *list = malloc(sizeof(linked_list_t));

    list->next = NULL;
    list->prev = NULL;
    list->nbr = 2000000000;
    return (list);
}

linked_list_t *move_end(linked_list_t *list)
{
    while (list->next)
        list = list->next;
    return (list);
}

linked_list_t *move_beginning(linked_list_t *list)
{
    while (list->prev)
        list = list->prev;
    return (list);
}

linked_list_t *add_nbr_to_linkedlist_end(linked_list_t *list, int nbr)
{
    linked_list_t *new = create_linkedlist();

    list->next = new;
    new->prev = list;
    new->nbr = nbr;
    return (new);
}

linked_list_t *arg_in_linkedlist(int size, char **av)
{
    linked_list_t *list = create_linkedlist();

    list->nbr = my_getnbr(av[1]);
    for (int i = 2; i <= size; ++i)
        list = add_nbr_to_linkedlist_end(list, my_getnbr(av[i]));
    return (list);
}