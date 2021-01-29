/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_projectil_list
*/

#include "my_defender.h"

projetcil_list_t *init_projectil_list(void)
{
    projetcil_list_t *projectil_list = malloc(sizeof(sprite_list_t));

    if (projectil_list == NULL)
        return (NULL);
    projectil_list->next = NULL;
    projectil_list->prev = NULL;
    projectil_list->projectil = NULL;
    return (projectil_list);
}