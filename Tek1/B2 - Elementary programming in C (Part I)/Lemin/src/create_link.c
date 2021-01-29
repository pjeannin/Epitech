/*
** EPITECH PROJECT, 2020
** Bootstrap_lem-in
** File description:
** create_lini
*/

#include "graph_utils.h"

link_t *create_link(int nb_link, char *data)
{
    link_t *link = malloc(sizeof(link_t));

    link->nb_link = nb_link;
    link->data = data;
    link->next = malloc(sizeof(link_t *) * (nb_link + 1));
    for (int i = 0; i <= nb_link; ++i)
        link->next[i] = NULL;
    return (link);
}

link_simple_t *create_simple_link(int data)
{
    link_simple_t *link = malloc(sizeof(link_simple_t));

    link->data = data;
    link->next = NULL;
    return (link);
}