/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** display_defense
*/

#include "my_defender.h"

void display_defense(defender_t *defender)
{
    if (defender && defender->defense_list);
    else
        return;
    while (defender->defense_list->prev)
        defender->defense_list = defender->defense_list->prev;
    while (defender->defense_list->next) {
        sfRenderWindow_drawSprite(defender->window,
        defender->defense_list->defnse->sprite->sprite, sfFalse);
        defender->defense_list = defender->defense_list->next;
    }
    if (defender->defense_list->defnse)
        sfRenderWindow_drawSprite(defender->window,
        defender->defense_list->defnse->sprite->sprite, sfFalse);
}