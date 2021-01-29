/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** defense_attack
*/

#include "my_defender.h"

int check_ennemy_pos(defender_t *defender)
{
    if (defender->ennemy_list->ennemy->pos.x >=
    defender->defense_list->defnse->pos.x -
    defender->defense_list->defnse->stroke * 128
    && defender->ennemy_list->ennemy->pos.x <=
    defender->defense_list->defnse->pos.x +
    defender->defense_list->defnse->stroke * 128
    && defender->ennemy_list->ennemy->pos.y >=
    defender->defense_list->defnse->pos.y -
    defender->defense_list->defnse->stroke * 128
    && defender->ennemy_list->ennemy->pos.y <=
    defender->defense_list->defnse->pos.y +
    defender->defense_list->defnse->stroke * 128)
        return (1);
    return (0);
}

int new_attack(defender_t *defender)
{
    if (check_ennemy_pos(defender) && defender->ennemy_list->ennemy->health > 0
    && defender->defense_list->defnse->shoot == 0) {
        if (defender->projectil_list->projectil == NULL)
            defender->projectil_list->projectil =
            add_projectil(defender->ennemy_list->ennemy,
            defender->defense_list->defnse);
        else {
            defender->projectil_list->next = malloc(sizeof(projectil_t));
            defender->projectil_list->next->prev = defender->projectil_list;
            defender->projectil_list = defender->projectil_list->next;
            defender->projectil_list->next = NULL;
            defender->projectil_list->projectil =
            add_projectil(defender->ennemy_list->ennemy,
            defender->defense_list->defnse);
        }
        if ((defender->defense_list->next == NULL) || 
            ((defender->projectil_list->projectil = add_projectil (
            defender->ennemy_list->ennemy,
            defender->defense_list->defnse)) == NULL) || 
            (defender->projectil_list->projectil =
            add_projectil(defender->ennemy_list->ennemy,
            defender->defense_list->defnse)) == NULL)
                return (1);
        defender->defense_list->defnse->shoot = 30;
    }
    return (0);
}

int defense_attack(defender_t *defender)
{
    while (defender->defense_list->prev)
        defender->defense_list = defender->defense_list->prev;
    while (defender->defense_list->next) {
        while (defender->ennemy_list->prev)
            defender->ennemy_list = defender->ennemy_list->prev;
        while (defender->ennemy_list->next) {
            if (new_attack(defender))
                return (1);
            defender->ennemy_list = defender->ennemy_list->next;
        }
        if (defender->defense_list->defnse->shoot)
            defender->defense_list->defnse->shoot -= 1;
        defender->defense_list = defender->defense_list->next;
    }
    if (defender->defense_list->next == NULL
    && defender->defense_list->defnse) {
        if (new_attack(defender))
            return (1);
        if (defender->defense_list->defnse->shoot)
            defender->defense_list->defnse->shoot -= 1;
    }
    return (0);
}