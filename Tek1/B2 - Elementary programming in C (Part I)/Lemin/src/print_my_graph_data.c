/*
** EPITECH PROJECT, 2020
** Bootstrap_lem-in
** File description:
** print_my_graph_data
*/

#include "graph_utils.h"

void print_my_graph_data(link_t *head_link)
{
    for (int i = 0; head_link->next[i]; ++i) {
        printf("from %s\n\n", head_link->data);
        print_my_graph_data(head_link->next[i]);
    }
    printf("data = %s\n", head_link->data);
}