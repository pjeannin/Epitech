/*
** EPITECH PROJECT, 2019
** sort_utils.c
** File description:
** push_swap
*/

#include <unistd.h>
#include <stdio.h>
#include "pushswap.h"

linked_list_t *rotate_left(linked_list_t *list)
{
    linked_list_t *parser;

    list = move_beginning(list);
    parser = list;
    (list->next)->prev = NULL;
    while (parser->next)
        parser = parser->next;
    parser->next = list;
    list->next = NULL;
    list->prev = parser;
    parser = move_beginning(parser);
    return (parser);
}

int is_sorted(linked_list_t *list)
{
    list = move_beginning(list);
    while (list->next) {
        if (list->nbr > (list->next)->nbr)
            return (1);
        list = list->next;
    }
    return (0);
}

int find_smallest(linked_list_t *list)
{
    int nbr = 2147483647;

    list = move_beginning(list);
    while (list->next) {
        if (list->nbr < nbr)
            nbr = list->nbr;
        list = list->next;
    }
    if (list->nbr < nbr)
        nbr = list->nbr;
    return (nbr);
}