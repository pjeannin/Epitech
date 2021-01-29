/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** find_link
*/

#include "graph_utils.h"
#include "my.h"

link_t *find_link(char *name, link_t **link_tab)
{
    for (int i = 0; link_tab[i]; ++i)
        if (my_strcmp(name, link_tab[i]->data) == 0)
            return (link_tab[i]);
    return (NULL);
}