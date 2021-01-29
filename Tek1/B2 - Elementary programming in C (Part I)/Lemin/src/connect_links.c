/*
** EPITECH PROJECT, 2020
** Bootstrap_lem-in
** File description:
** connect_links
*/

#include "graph_utils.h"
#include "my.h"

void connect_links_simple(link_simple_t *link1, link_simple_t *link2)
{
    for(; link1->next; link1 = link1->next);
    link1->next = link2;
}

void connect_links(link_t *link1, link_t *link2)
{
    int i = 0;

    for (; link1->next[i] != NULL && i < link1->nb_link; ++i);
    link1->next[i] = link2;
    i = 0;
    for (; link2->next[i] != NULL && i < link2->nb_link; ++i);
    link2->next[i] = link1;
}