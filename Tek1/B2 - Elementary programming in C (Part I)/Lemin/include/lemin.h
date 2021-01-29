/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** lemin.h
*/
#pragma once

#include "graph_utils.h"

typedef struct lemin_s {
    link_t *grap_origin;
    char *start;
    char *end;
    int nb_ants;
} lemin_t;