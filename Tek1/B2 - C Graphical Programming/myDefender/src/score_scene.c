/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** score_scene
*/

#include "my_defender.h"

void score_scene(defender_t *defender)
{
    display_map(defender->current_map, defender->window);
    display_score_button(defender);
    display_score(defender);
    event_score_scene(defender);
}