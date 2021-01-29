/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** free_defender
*/

#include "my_defender.h"

void free_castle(castle_t *castle)
{
    free_picture(castle->display_sprite);
    free_picture(castle->full_life);
    free_picture(castle->low_life);
    free_picture(castle->mid_life);
    free_picture(castle->no_life);
    free_picture(castle->third_life);
    free(castle);
}

void free_defense(defense_t *defense)
{
    free_picture(defense->sprite);
}

void free_ennemy(ennemy_t *ennemy)
{
    free_picture(ennemy->full_life);
    free_picture(ennemy->third_life);
    free_picture(ennemy->low_life);
    free_picture(ennemy->mid_life);
    free_picture(ennemy->no_life);
    free_picture(ennemy->sprite_list->sprite);
}

void free_defense_list(defense_list_t *list)
{
    while (list->prev)
        list = list->prev;
    while (list->next) {
        if (list->defnse)
            free_defense(list->defnse);
        list = list->next;
        if (list->prev)
            free(list->prev);
    }
    free(list);
}

void free_ennemy_list(ennemy_list_t *list)
{
    while (list->prev)
        list = list->prev;
    while (list->next) {
        if (list->ennemy)
            free_ennemy(list->ennemy);
        list = list->next;
        if (list->prev)
            free(list->prev);
    }
    free(list);
}