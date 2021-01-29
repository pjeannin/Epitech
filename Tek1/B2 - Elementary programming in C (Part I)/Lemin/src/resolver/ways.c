/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** ways.c
*/
#include "resolver.h"

void resolve(lemin_t *lemin)
{
    printf("ez");
}

int get_next_way(link_t *current, link_t *end)
{
    link_t *has_end;

    for (int i = 0; i < current->nb_link; i++)
        if (current->next[i] == end)
            has_end = current->next[i];
    if (has_end)
        return (0);
    for (int i = 0; i < current->nb_link; i++)
        get_next_way(current->next[i], end);
    return (1);
}