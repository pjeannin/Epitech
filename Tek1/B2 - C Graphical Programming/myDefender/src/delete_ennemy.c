/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** delete_ennemy
*/

#include "my_defender.h"

void delete_ennemy_end(defender_t *defender)
{
    if (!defender->ennemy_list->next)
        defender->ennemy_list->prev->next = NULL;
    else if (!defender->ennemy_list->prev)
        defender->ennemy_list->next->prev = NULL;
    else {
        defender->ennemy_list->prev->next = defender->ennemy_list->next;
        defender->ennemy_list->next->prev = defender->ennemy_list->prev;
    }
}

void delete_ennemy_mid(defender_t *defender)
{
    if (!defender->ennemy_list->next && !defender->ennemy_list->prev)
        defender->ennemy_list->ennemy = NULL;
    else
        delete_ennemy_end(defender);
}

void delete_ennemy(defender_t *defender)
{
    while (defender->ennemy_list->prev)
        defender->ennemy_list = defender->ennemy_list->prev;
    while (defender->ennemy_list->next) {
        if (defender->ennemy_list->ennemy->health <= 0) {
            defender->money++;
            delete_ennemy_mid(defender);
        }
        defender->ennemy_list = defender->ennemy_list->next;
    }
}