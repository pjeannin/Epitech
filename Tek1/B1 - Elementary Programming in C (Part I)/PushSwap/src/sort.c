/*
** EPITECH PROJECT, 2019
** sort.c
** File description:
** pushswap
*/

#include <unistd.h>
#include <stdio.h>
#include "pushswap.h"

void b_in_a(linked_list_t **lista, linked_list_t **listb)
{
    *lista = add_nbr_to_linkedlist_beginning(*lista, (*listb)->nbr);
    if ((*listb)->next) {
        *listb = (*listb)->next;
        write(1, "pa ", 3);
    } else {
        write(1, "pa", 2);
        *listb = NULL;
    }
}

void a_in_b(linked_list_t **lista, linked_list_t **listb)
{
    int smallest;

    *lista = move_beginning(*lista);
    smallest = find_smallest(*lista);
    *lista = move_beginning(*lista);
    while ((*lista)->nbr != smallest) {
        *lista = rotate_left(*lista);
        write(1, "ra ", 3);
    }
    if ((*listb)->nbr == 2000000000)
        (*listb)->nbr = (*lista)->nbr;
    else
        *listb = add_nbr_to_linkedlist_beginning(*listb, (*lista)->nbr);
    *lista = (*lista)->next;
    (*lista)->prev = NULL;
    write(1, "pb ", 3);
}

linked_list_t *sort(linked_list_t *lista)
{
    int smallest;
    linked_list_t *listb = create_linkedlist();

    lista = move_beginning(lista);
    if (is_sorted(lista) == 0) {
        write(1, "\n", 1);
        return (lista);
    }
    while (is_sorted(lista))
        a_in_b(&lista, &listb);
    while (listb)
        b_in_a(&lista, &listb);
    write(1, "\n", 1);
    return (lista);
}