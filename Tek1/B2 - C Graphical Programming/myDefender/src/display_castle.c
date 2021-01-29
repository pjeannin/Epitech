/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** display_castle
*/

#include "my_defender.h"

void end_display_castle(defender_t *defender)
{
    if (defender->castle->health >= defender->castle->init_health * 0.25)
        sfRenderWindow_drawSprite(defender->window,
        defender->castle->mid_life->sprite, sfFalse);
    else if (defender->castle->health > 0)
        sfRenderWindow_drawSprite(defender->window,
        defender->castle->low_life->sprite, sfFalse);
    else
        sfRenderWindow_drawSprite(defender->window,
        defender->castle->no_life->sprite, sfFalse);
}

void display_castle(defender_t *defender)
{
    sfRenderWindow_drawSprite(defender->window,
    defender->castle->display_sprite->sprite, sfFalse);
    if (defender->castle->health >= defender->castle->init_health * 0.75)
        sfRenderWindow_drawSprite(defender->window,
        defender->castle->full_life->sprite, sfFalse);
    else if (defender->castle->health >= defender->castle->init_health * 0.5)
        sfRenderWindow_drawSprite(defender->window,
        defender->castle->third_life->sprite, sfFalse);
    else
        end_display_castle(defender);
}