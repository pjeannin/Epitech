/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** free_defender
*/

#include "my_defender.h"

void free_map(sprite_list_t *list)
{
    while (list->prev)
        list = list->prev;
    while (list->next) {
        free_picture(list->sprite);
        list = list->next;
    }
    free(list);
}

void free_projectil_list(projetcil_list_t *list)
{
    while (list->prev)
        list = list->prev;
    while (list->next) {
        free_picture(list->projectil->sprite);
        list = list->next;
    }
    free(list);
}