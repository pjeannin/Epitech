/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** load_graph
*/

#include "graph_utils.h"
#include "lemin.h"
#include "load_graph.h"
#include "my.h"

void load_graph(lemin_t *lemin_struct, char **input)
{
    cell_t *cell_list = init_cell_list(NULL, NULL);

    lemin_struct->grap_origin = malloc(sizeof(link_t));
    for (int i = 0; input[i]; ++i)
        if (is_in_str('-', input[i]))
            cell_list = load_line(cell_list, input[i]);
    for (; cell_list->prev; cell_list = cell_list->prev);
    lemin_struct->grap_origin = transform_list_in_graph(input, cell_list);
}