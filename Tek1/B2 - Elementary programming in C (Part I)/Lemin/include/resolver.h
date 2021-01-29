/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** load_infos
*/
#pragma once

#include "lemin.h"
#include "graph_utils.h"

typedef struct way_t way_t;
typedef struct ways_storage_t ways_storage_t;

struct way_t {
    char *data;
    link_t *next;
};

struct ways_storage_t {
    ways_storage_t *next;
    way_t *(ways)[256];
    int size;
};

void resolve(lemin_t *lemin);