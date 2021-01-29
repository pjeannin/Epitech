/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** main_menu_scene
*/

#include "my_defender.h"

void main_menu_scene(defender_t *defender)
{
    display_map(defender->map1, defender->window);
    draw_main_menu_button(defender);
    event_main_menu_scene(defender);
}