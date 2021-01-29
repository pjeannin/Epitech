/*
** EPITECH PROJECT, 2019
** utils_linked_list_bis.c
** File description:
** pushswap
*/

#include <stdlib.h>
#include <unistd.h>
#include "pushswap.h"

void display_linked_list_all_next(linked_list_t *list)
{
    while (list->next) {
        put_nbr(list->nbr);
        write(1, "\n", 1);
        list = list->next;
    }
    put_nbr(list->nbr);
}

void display_linked_list_all_prev(linked_list_t *list)
{
    while (list->prev) {
        put_nbr(list->nbr);
        write(1, "\n", 1);
        list = list->prev;
    }
    put_nbr(list->nbr);
}

void display_all_linked_list(linked_list_t *list)
{
    list = move_beginning(list);

    display_linked_list_all_next(list);
}

void linked_list_swap(linked_list_t *node1, linked_list_t *node2)
{
    int nbr = node1->nbr;

    node1->nbr = node2->nbr;
    node2->nbr = nbr;
}

void free_linked_list(linked_list_t *list)
{
    list = move_beginning(list);
    while (list->next) {
        list = list->next;
        free(list->prev);
    }
    free(list);
}