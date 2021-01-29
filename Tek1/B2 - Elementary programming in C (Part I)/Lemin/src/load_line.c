/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** load_line
*/

#include "load_graph.h"
#include "my.h"

cell_t *load_cell(cell_t *cell_list, char *name)
{
    for (; cell_list->prev; cell_list = cell_list->prev);
    for (; cell_list->next; cell_list = cell_list->next) {
        if (my_strcmp(cell_list->name, name) == 0) {
            ++cell_list->nb_link;
            return (cell_list);
        }
    }
    if (my_strcmp(cell_list->name, name) == 0) {
        ++cell_list->nb_link;
        return (cell_list);
    }
    cell_list->next = init_cell_list(name, cell_list);
    return (cell_list);
}

char *read_first_part(char *line)
{
    char *first_part = malloc(sizeof(char) * my_strlen(line));
    int i = 0;

    for (; line[i] != '-'; ++i)
        first_part[i] = line[i];
    first_part[i] = '\0';
    return (first_part);
}

char *read_second_part(char *line)
{
    char *second_part = malloc(sizeof(char) * my_strlen(line));
    int i = 0;
    int start = 0;

    for (int j = 0; line[j] && line[j] != ' '; ++j) {
        if (start == 0) {
            if (line[j] == '-')
                start = 1;
        } else {
            second_part[i] = line[j];
            ++i;
        }
    }
    second_part[i] = '\0';
    return (second_part);
}

cell_t *load_line(cell_t *cell_list, char *line)
{
    char *first_part = read_first_part(line);
    char *second_part = read_second_part(line);
    static int call = 0;

    if (call == 0) {
        cell_list->name = first_part;
        cell_list->nb_link = 1;
        ++call;
    } else
        cell_list = load_cell(cell_list, first_part);
    cell_list = load_cell(cell_list, second_part);
    return (cell_list);
}