/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** get_label_offset
*/

#include "includes.h"

bool get_label_offset(char *line, int *value, cor_t *cor)
{
    while (cor->label_list) {
        if (my_strcomp(line, cor->label_list->name)) {
            *value = cor->head - cor->label_list->position;
            return (false);
        }
        NEXT(cor->label_list);
    }
    return (true);
}