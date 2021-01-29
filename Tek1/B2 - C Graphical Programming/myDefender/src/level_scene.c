/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** level_scene
*/

#include "my_defender.h"

void level_scene(defender_t *defender)
{
    display_map(defender->map1, defender->window);
    display_level_button(defender);
    event_level_scene(defender);
}