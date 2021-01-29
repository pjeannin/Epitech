/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** draw_main_menu_button
*/

#include "my_defender.h"

void draw_main_menu_button(defender_t *defender)
{
    sfRenderWindow_drawRectangleShape(defender->window,
    defender->button_list->play_button->button, sfFalse);
    sfRenderWindow_drawRectangleShape(defender->window,
    defender->button_list->rules_button->button, sfFalse);
    sfRenderWindow_drawText(defender->window,
    defender->button_list->rules_text, sfFalse);
    sfRenderWindow_drawText(defender->window,
    defender->button_list->play_text, sfFalse);
}