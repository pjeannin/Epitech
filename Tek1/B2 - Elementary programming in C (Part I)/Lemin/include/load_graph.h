/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** load_graph
*/

#include "lemin.h"

#ifndef LOAD_GRAPH_H_
#define LOAD_GRAPH_H_

typedef struct cell_s {
    char *name;
    int nb_link;
    struct cell_s *next;
    struct cell_s *prev;
} cell_t;

void load_graph(lemin_t *lemin_struct, char **input);
cell_t *init_cell_list(char *name, cell_t *prev);
cell_t *load_line(cell_t *cell_list, char *line);
link_t *transform_list_in_graph(char **input, cell_t *cell_list);
char *read_first_part(char *line);
char *read_second_part(char *line);

#endif /* !LOAD_GRAPH_H_ */
