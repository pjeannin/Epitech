/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** display_level_button
*/

#include "my_defender.h"

void display_level_button(defender_t *defender)
{
    sfRenderWindow_drawRectangleShape(defender->window,
    defender->button_list->level1_button->button, sfFalse);
    sfRenderWindow_drawRectangleShape(defender->window,
    defender->button_list->level2_button->button, sfFalse);
    sfRenderWindow_drawRectangleShape(defender->window,
    defender->button_list->level3_button->button, sfFalse);
    sfRenderWindow_drawText(defender->window,
    defender->button_list->level1_text, sfFalse);
    sfRenderWindow_drawText(defender->window,
    defender->button_list->level2_text, sfFalse);
    sfRenderWindow_drawText(defender->window,
    defender->button_list->level3_text, sfFalse);
}
