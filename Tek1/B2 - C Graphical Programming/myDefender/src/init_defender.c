/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_defender
*/

#include "my_defender.h"

defender_t *init_defender(void)
{
    defender_t *defender = malloc(sizeof(defender_t));

    if (defender == NULL)
        return (NULL);
    defender->button_list = init_button_list();
    defender->map1 = load_map("maps/map1", &defender->map1_construction);
    defender->map2 = load_map("maps/map2", &defender->map2_construction);
    defender->map3 = load_map("maps/map2", &defender->map3_construction);
    if (!defender->map1) {
        free(defender);
        return (NULL);
    }
    defender->window = creat_window(1920, 1080, "My Defender");
    defender->current_scene = 0;
    defender->current_map = defender->map1;
    defender->current_mapconstruction = defender->map1_construction;
    defender->score = 0;
    defender->high_score = 0;
    defender->level = 1;
    return (defender);
}