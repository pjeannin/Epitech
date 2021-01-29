/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** event_level_scene
*/

#include "my_defender.h"

int load_level(defender_t *defender)
{
    defender->current_scene = 4;
    if ((defender->defense_list = create_empty_defense_list()) == NULL)
        return (1);
    if ((defender->ennemy_list = create_empty_ennemy_list()) == NULL)
        return (1);
    if ((defender->projectil_list = create_empty_projectil_list()) == NULL)
        return (1);
    defender->money = 2;
    return (0);
}

int load_level_one(defender_t *defender, sfEvent event)
{
    if (button_is_clic(event, defender->button_list->level1_button)) {
        defender->current_map = defender->map1;
        defender->current_mapconstruction = defender->map1_construction;
        if ((defender->castle = init_castle(1)) == NULL)
            return (1);
        defender->level = 1;
        load_level(defender);
    }
    return (0);
}

int load_level_two(defender_t *defender, sfEvent event)
{
    if (button_is_clic(event, defender->button_list->level2_button)) {
        defender->current_map = defender->map2;
        defender->current_mapconstruction = defender->map2_construction;
        if ((defender->castle = init_castle(2)) == NULL)
            return (1);
        defender->level = 2;
        load_level(defender);
    }
    return (0);
}

int load_level_three(defender_t *defender, sfEvent event)
{
    if (button_is_clic(event, defender->button_list->level3_button)) {
        defender->current_map = defender->map3;
        defender->current_mapconstruction = defender->map3_construction;
        if ((defender->castle = init_castle(2)) == NULL)
            return (1);
        defender->level = 3;
        load_level(defender);
    }
    return (0);
}

void event_level_scene(defender_t *defender)
{
    sfEvent event;
    int init_game = 0;

    while (sfRenderWindow_pollEvent(defender->window, &event)) {
        load_level_one(defender, event);
        load_level_two(defender, event);
        load_level_three(defender, event);
        if (button_is_clic(event, defender->button_list->exit_button))
            sfRenderWindow_close(defender->window);
    }
}