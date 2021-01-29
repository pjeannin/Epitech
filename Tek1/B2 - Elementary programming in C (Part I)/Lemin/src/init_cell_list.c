/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** init_cell_list
*/

#include "load_graph.h"

cell_t *init_cell_list(char *name, cell_t *prev)
{
    cell_t *cell = malloc(sizeof(cell_t));

    cell->name = name;
    cell->nb_link = 1;
    cell->next = NULL;
    cell->prev = prev;
    return (cell);
}