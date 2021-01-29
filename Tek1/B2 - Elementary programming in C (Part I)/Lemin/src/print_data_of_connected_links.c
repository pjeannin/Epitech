/*
** EPITECH PROJECT, 2020
** Bootstrap_lem-in
** File description:
** print_data_of_connected_links
*/

#include "graph_utils.h"

void print_data_of_connected_links(link_simple_t *link)
{
    for (; link->next; link = link->next)
        print_link(link);
    print_link(link);
}