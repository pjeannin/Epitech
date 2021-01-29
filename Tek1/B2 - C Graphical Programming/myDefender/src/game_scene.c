/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** game_scene
*/

#include "my_defender.h"

void game_scene(defender_t *defender)
{
    defender->score++;
    if (defender->castle->health <= 0)
        defender->current_scene = 5;
    display_map(defender->current_map, defender->window);
    display_castle(defender);
    display_ennemy(defender);
    display_projectil(defender);
    display_defense(defender);
    dipslay_game_button(defender);
    display_player_money(defender);
    move_projectil(defender);
    defense_attack(defender);
    ennemy_attack(defender);
    move_all_ennemy(defender);
    delete_ennemy(defender);
    add_ennemy(defender);
    game_scene_event(defender);
}