/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_label
*/

#include "includes.h"

bool get_label(char **line, cor_t *cor)
{
    //printf ("before skip :%s\n", *line);
    skip_flag(line, " \t", 0, true);
    //printf ("after skip :%s\n", *line);
    for (u_int32_t i = 0; (*line)[i] && !is_in((*line)[i], " \t"); ++i) {
        if ((*line)[i] == LABEL_CHAR && is_in((*line)[i + 1], " \t")) {
            add_new_label(&cor->label_list, my_strndup(*line, i), cor->head);
            *line += i + 1;
            return (false);
        } else if ((*line)[i] == LABEL_CHAR && !is_in((*line)[i + 1], " \t"))
            return (true);
    }
    return (false);
}
