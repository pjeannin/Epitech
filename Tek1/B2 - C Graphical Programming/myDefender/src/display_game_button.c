/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** dipslay_game_button
*/

#include "my_defender.h"

void dipslay_game_button(defender_t *defender)
{
    sfRectangleShape *gray_background = sfRectangleShape_create();

    sfRectangleShape_setPosition(gray_background, create_sfvector2f(1500, 80));
    sfRectangleShape_setSize(gray_background, create_sfvector2f(400, 780));
    sfRectangleShape_setOutlineColor(gray_background, sfBlack);
    sfRectangleShape_setFillColor(gray_background, sfBlack);
    sfRenderWindow_drawRectangleShape(defender->window, gray_background,
    sfFalse);
    sfRectangleShape_destroy(gray_background);
    sfRenderWindow_drawSprite(defender->window,
    defender->button_list->defense1->button->sprite, sfFalse);
    sfRenderWindow_drawSprite(defender->window,
    defender->button_list->defense2->button->sprite, sfFalse);
    sfRenderWindow_drawSprite(defender->window,
    defender->button_list->pause->button->sprite, sfFalse);
}