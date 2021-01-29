/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** intro_scene
*/

#include "my_defender.h"

int init_intro_scene(defender_t *defender)
{
    defender->ennemy_list = init_ennemy_list(3, defender);
    defender->defense_list = init_defense_list();
    if ((defender->castle = init_castle(1)) == NULL)
        return (1);
    defender->projectil_list = init_projectil_list();
    return (0);
}

void intro_scene(defender_t *defender)
{
    static int call = 0;

    if (call++ > 1000)
        defender->current_scene = 1;
    if (call == 1)
        init_intro_scene(defender);
    display_map(defender->map1, defender->window);
    display_ennemy(defender);
    ennemy_attack(defender);
    display_castle(defender);
    display_defense(defender);
    defense_attack(defender);
    display_projectil(defender);
    move_projectil(defender);
    move_all_ennemy(defender);
    delete_ennemy(defender);
    event_intro_scene(defender);
}