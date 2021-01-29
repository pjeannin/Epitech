/*
** EPITECH PROJECT, 2020
** label_linked_list
** File description:
** label_linked_list
*/

#include "includes.h"

bool add_new_label(label_t **current, char const *name, u_int32_t position)
{
    label_t *new = malloc(sizeof(label_t));

    if (!new) return (true);
    printf ("label name %s\n", name);
    new->name = name;
    new->position = position;
    new->next = *current;
    *current = new;
    return (false);
}