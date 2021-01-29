/*
** EPITECH PROJECT, 2019
** utils_linked_list_bis_bis.c
** File description:
** pushswap
*/

#include <stdlib.h>
#include "pushswap.h"

void remove_node(linked_list_t *node)
{
    if (node->next)
        (node->next)->prev = node->prev;
    else
        (node->prev)->next = NULL;
    if (node->prev)
        (node->prev)->next = node->next;
    else
        (node->next)->prev = NULL;
}

linked_list_t *add_nbr_to_linkedlist_beginning(linked_list_t *list, int nbr)
{
    linked_list_t *new = create_linkedlist();

    list = move_beginning(list);
    new->next = list;
    new->nbr = nbr;
    return (new);
}