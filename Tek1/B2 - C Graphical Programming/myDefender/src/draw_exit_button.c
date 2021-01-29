/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** draw_exit_button
*/

#include "my_defender.h"

void draw_exit_button(defender_t *defender, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window,
    defender->button_list->exit_button->button, sfFalse);
    sfRenderWindow_drawText(window, defender->button_list->exit_text, sfFalse);
}