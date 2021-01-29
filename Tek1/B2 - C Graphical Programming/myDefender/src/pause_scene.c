/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** pause_scene
*/

#include "my_defender.h"

void pause_scene(defender_t *defender)
{
    picture_t *blur = init_image("PNG/blur.png", 0, 0, 0);

    display_map(defender->current_map, defender->window);
    display_castle(defender);
    display_projectil(defender);
    display_defense(defender);
    display_player_money(defender);
    sfRenderWindow_drawSprite(defender->window, blur->sprite, sfFalse);
    display_pause_scene_button(defender);
    event_pause_scene(defender);
}