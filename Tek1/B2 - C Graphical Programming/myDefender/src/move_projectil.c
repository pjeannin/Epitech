/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** move_project
*/

#include "my_defender.h"

void set_new_position(defender_t *defender)
{
    sfVector2f director_vector;

    director_vector.x = (defender->projectil_list->projectil->ennemy_id->pos.x -
    defender->projectil_list->projectil->sprite->pos.x) * 0.025;
    director_vector.y =( defender->projectil_list->projectil->ennemy_id->pos.y -
    defender->projectil_list->projectil->sprite->pos.y) * 0.025;
    defender->projectil_list->projectil->sprite->pos.x += director_vector.x;
    defender->projectil_list->projectil->sprite->pos.y += director_vector.y;
    sfSprite_setPosition(defender->projectil_list->projectil->sprite->sprite,
    defender->projectil_list->projectil->sprite->pos);
}

void delete_projectil(defender_t *defender)
{
    if (!defender->projectil_list->next && !defender->projectil_list->prev) {
        defender->projectil_list->projectil = NULL;
    } else {
        if (!defender->projectil_list->next)
            defender->projectil_list->prev->next = NULL;
        else if (!defender->projectil_list->prev)
            defender->projectil_list->next->prev = NULL;
        else {
            defender->projectil_list->prev->next =
            defender->projectil_list->next;
            defender->projectil_list->next->prev =
            defender->projectil_list->prev;
        }
    }
}

void move_projectil_end(defender_t *defender)
{
    if (defender->projectil_list->projectil) {
        set_new_position(defender);
        if (defender->projectil_list->projectil->sprite->pos.y <=
        defender->projectil_list->projectil->ennemy_id->pos.y + 20
        && defender->projectil_list->projectil->sprite->pos.y >=
        defender->projectil_list->projectil->ennemy_id->pos.y - 20) {
            defender->projectil_list->projectil->ennemy_id->health -= 15;
            delete_projectil(defender);
        }
    }
}

void move_projectil(defender_t *defender)
{
    while (defender->projectil_list->prev)
        defender->projectil_list = defender->projectil_list->prev;
    while (defender->projectil_list->next) {
        set_new_position(defender);
        if (defender->projectil_list->projectil->sprite->pos.y <=
        defender->projectil_list->projectil->ennemy_id->pos.y + 20
        && defender->projectil_list->projectil->sprite->pos.y >=
        defender->projectil_list->projectil->ennemy_id->pos.y - 20) {
            defender->projectil_list->projectil->ennemy_id->health -= 15;
            delete_projectil(defender);
        }
        defender->projectil_list = defender->projectil_list->next;
    }
    move_projectil_end(defender);
}