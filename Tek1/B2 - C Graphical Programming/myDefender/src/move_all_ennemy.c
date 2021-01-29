/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** move_all_ennemy
*/

#include "my_defender.h"

void move_all_ennemy(defender_t *defender)
{
    while (defender->ennemy_list->prev)
        defender->ennemy_list = defender->ennemy_list->prev;
    while (defender->ennemy_list->next) {
        move_ennemy(defender, defender->ennemy_list->ennemy);
        defender->ennemy_list = defender->ennemy_list->next;
    }
}