/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** display_score_button
*/

#include "my_defender.h"

void display_score_button(defender_t *defender)
{
    sfRenderWindow_drawRectangleShape(defender->window,
    defender->button_list->menu_button->button, sfFalse);
    sfRenderWindow_drawText(defender->window, defender->button_list->menu_text,
    sfFalse);
    sfRenderWindow_drawRectangleShape(defender->window,
    defender->button_list->play_again_button->button, sfFalse);
    sfRenderWindow_drawText(defender->window,
    defender->button_list->play_again_text, sfFalse);
}