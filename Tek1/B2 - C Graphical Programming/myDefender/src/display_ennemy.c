/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** display_ennemy
*/

#include "my_defender.h"

void display_ennemy_end(defender_t *defender)
{
    if (defender->ennemy_list->ennemy->health >=
    defender->ennemy_list->ennemy->init_health * 0.25)
        sfRenderWindow_drawSprite(defender->window,
        defender->ennemy_list->ennemy->mid_life->sprite, sfFalse);
    else if (defender->ennemy_list->ennemy->health > 0)
        sfRenderWindow_drawSprite(defender->window,
        defender->ennemy_list->ennemy->low_life->sprite, sfFalse);
    else
        sfRenderWindow_drawSprite(defender->window,
        defender->ennemy_list->ennemy->no_life->sprite, sfFalse);
}

void display_ennemy(defender_t *defender)
{
    while (defender->ennemy_list->prev)
        defender->ennemy_list = defender->ennemy_list->prev;
    while (defender->ennemy_list->next) {
        sfRenderWindow_drawSprite(defender->window,
        defender->ennemy_list->ennemy->sprite_list->sprite->sprite, sfFalse);
        if (defender->ennemy_list->ennemy->health >=
        defender->ennemy_list->ennemy->init_health * 0.75)
            sfRenderWindow_drawSprite(defender->window,
            defender->ennemy_list->ennemy->full_life->sprite, sfFalse);
        else if (defender->ennemy_list->ennemy->health >=
        defender->ennemy_list->ennemy->init_health * 0.5)
            sfRenderWindow_drawSprite(defender->window,
            defender->ennemy_list->ennemy->third_life->sprite, sfFalse);
        else
            display_ennemy_end(defender);
        defender->ennemy_list = defender->ennemy_list->next;
    }
}