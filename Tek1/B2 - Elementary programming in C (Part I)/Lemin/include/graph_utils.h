/*
** EPITECH PROJECT, 2020
** Bootstrap_lem-in
** File description:
** graph
*/
#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct link_s {
    int nb_link;
    char *data;
    struct link_s **next;
} link_t;

typedef struct link_simple_s {
    int data;
    struct link_simple_s *next;
} link_simple_t;

link_t *create_link(int nb_link, char *data);
link_simple_t *create_simple_link(int data);
void print_link(link_simple_t *link);
void print_data_of_connected_links(link_simple_t *link);
void connect_links_simple(link_simple_t *link1, link_simple_t *link2);
void connect_links(link_t *link1, link_t *link2);
void print_my_graph_data(link_t *head_link);
link_t *find_link(char *name, link_t **link_tab);