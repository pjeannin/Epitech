/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** display_pause_scene_button
*/

#include "my_defender.h"

void display_pause_scene_button(defender_t *defender)
{
    sfRenderWindow_drawSprite(defender->window,
    defender->button_list->pause->button->sprite, sfFalse);
    sfRenderWindow_drawRectangleShape(defender->window,
    defender->button_list->restart_button->button, sfFalse);
    sfRenderWindow_drawRectangleShape(defender->window,
    defender->button_list->resume_button->button, sfFalse);
    sfRenderWindow_drawRectangleShape(defender->window,
    defender->button_list->main_menu_button->button, sfFalse);
    sfRenderWindow_drawText(defender->window,
    defender->button_list->restart_text, sfFalse);
    sfRenderWindow_drawText(defender->window,
    defender->button_list->resume_text, sfFalse);
    sfRenderWindow_drawText(defender->window,
    defender->button_list->main_menu_text, sfFalse);
}