/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** display_projectil
*/

#include "my_defender.h"

void display_projectil(defender_t *defender)
{
    while (defender->projectil_list->prev)
        defender->projectil_list = defender->projectil_list->prev;
    while (defender->projectil_list->next) {
        if (defender->projectil_list->projectil->display)
            sfRenderWindow_drawSprite(defender->window,
        defender->projectil_list->projectil->sprite->sprite, sfFalse);
        defender->projectil_list = defender->projectil_list->next;
    }
    if (defender->projectil_list->projectil
    && defender->projectil_list->projectil->display)
        sfRenderWindow_drawSprite(defender->window,
    defender->projectil_list->projectil->sprite->sprite, sfFalse);
}