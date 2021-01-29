/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** free_defender
*/

#include "my_defender.h"

void free_defender_end_end(defender_t *defender)
{
    if (defender->map1_construction)
        free_construction_map(defender->map1_construction);
    if (defender->map2_construction)
        free_construction_map(defender->map2_construction);
    if (defender->map3_construction)
        free_construction_map(defender->map3_construction);
}

void free_defender_end(defender_t *defender)
{
    if (defender->map2)
        free_map(defender->map2);
    if (defender->projectil_list)
        free_projectil_list(defender->projectil_list);
    free_defender_end_end(defender);
    if (defender->map3)
        free_map(defender->map3);
    free(defender);
}

void free_defender_mid_mid(defender_t *defender)
{
    if (defender->ennemy_list)
        free_ennemy_list(defender->ennemy_list);
    if (defender->map1)
        free_map(defender->map1);
    free_defender_end(defender);
}

void free_defender_mid(defender_t *defender)
{
    if (defender->castle)
        free_castle(defender->castle);
    if (defender->defense_list)
        free_defense_list(defender->defense_list);
    free_defender_mid_mid(defender);
}

void free_defender(defender_t *defender)
{
    if (!defender)
        return;
    if (defender->button_list)
        free_button_list(defender->button_list);
    free_defender_mid(defender);
}