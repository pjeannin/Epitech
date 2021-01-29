/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ennemy_attack
*/

#include "my_defender.h"

int attck_is_possible(defender_t *defender)
{
    if ((defender->castle->pos.x + 192) / 128 >=
    (defender->ennemy_list->ennemy->pos.x + 64) / 128 -
    defender->ennemy_list->ennemy->shoot_length
    && (defender->castle->pos.x + 192) / 128 <=
    (defender->ennemy_list->ennemy->pos.x + 64) / 128 +
    defender->ennemy_list->ennemy->shoot_length
    && (defender->castle->pos.y + 192) / 128 >=
    (defender->ennemy_list->ennemy->pos.y + 64) / 128 -
    defender->ennemy_list->ennemy->shoot_length
    && (defender->castle->pos.y + 192) / 128 <=
    (defender->ennemy_list->ennemy->pos.y + 64) / 128 +
    defender->ennemy_list->ennemy->shoot_length)
        return (1);
    return (0);
}

void ennemy_attack(defender_t *defender)
{
    while (defender->ennemy_list->prev)
        defender->ennemy_list = defender->ennemy_list->prev;
    while (defender->ennemy_list->next) {
        if (attck_is_possible(defender)) {
            if (defender->ennemy_list->ennemy->shoot == 0) {
            defender->castle->health -= 7;
            defender->ennemy_list->ennemy->shoot = 15;
            }
        }
        if (defender->ennemy_list->ennemy->shoot)
            defender->ennemy_list->ennemy->shoot -= 1;
        defender->ennemy_list = defender->ennemy_list->next;
    }
}