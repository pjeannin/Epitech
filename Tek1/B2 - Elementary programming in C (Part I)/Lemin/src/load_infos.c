/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** load_infos
*/

#include "my.h"
#include "load_graph.h"
#include "lemin.h"

static char *read_start_end(char *line)
{
    char *ret_val = malloc(sizeof(char) * my_strlen(line));
    int i = 0;

    for (; line[i] && line[i] != ' '; ++i)
        ret_val[i] = line[i];
    ret_val[i] = '\0';
    return (ret_val);
}

lemin_t *load_infos(char **input)
{
    lemin_t *lemin_struct = malloc(sizeof(lemin_t));
    int index = 0;

    if (!lemin_struct)
        return ((lemin_t *)-1);
    lemin_struct->nb_ants = my_getnbr(input[0]);
    for (; my_strcmp("##start", input[index]); ++index);
    lemin_struct->start = read_start_end(input[index + 1]);
    index = 0;
    for (; my_strcmp("##end", input[index]); ++index);
    lemin_struct->end = read_start_end(input[index + 1]);
    return (lemin_struct);
}