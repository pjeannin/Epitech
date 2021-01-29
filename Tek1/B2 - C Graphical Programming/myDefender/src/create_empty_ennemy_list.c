/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_empty_ennemy_list
*/

#include "my_defender.h"

ennemy_list_t *create_empty_ennemy_list(void)
{
    ennemy_list_t *ennemy_list = malloc(sizeof(ennemy_list_t));

    if (ennemy_list == NULL)
        return (NULL);
    ennemy_list->prev = NULL;
    ennemy_list->next = NULL;
    ennemy_list->ennemy = NULL;
    return (ennemy_list);
}