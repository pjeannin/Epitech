/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** transform_list_in_graph
*/

#include "lemin.h"
#include "load_graph.h"
#include "graph_utils.h"
#include "my.h"

int cell_list_len(cell_t *cell_list)
{
    int len = 0;

    for (; cell_list->prev; cell_list = cell_list->prev);
    for (; cell_list->next; cell_list = cell_list->next)
        ++len;
    return (len);
}

link_t **fill_link_list(cell_t *cell_list, link_t **link_list)
{
    int i = 0;

    for (; cell_list->prev; cell_list = cell_list->prev);
    for (; cell_list->next; cell_list = cell_list->next) {
        link_list[i] = create_link(cell_list->nb_link, cell_list->name);
        ++i;
    }
    link_list[i] = create_link(cell_list->nb_link, cell_list->name);
    ++i;
    link_list[i] = NULL;
    return (link_list);
}

link_t *transform_list_in_graph(char **input, cell_t *cell_list)
{
    link_t **link_list = malloc(sizeof(link_t *) *
    (cell_list_len(cell_list) + 2));
    link_t *graph_origin;

    link_list = fill_link_list(cell_list, link_list);
    for (int i = 0; input[i]; ++i)
        if (is_in_str('-', input[i]))
            connect_links(find_link(read_first_part(input[i]), link_list),
            find_link(read_second_part(input[i]), link_list));
    graph_origin = link_list[0];
    return (graph_origin);
}