/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_ennemy
*/

#include "my_defender.h"

void add_images(ennemy_t *ennemy)
{
    ennemy->sprite_list->sprite =
    init_image("PNG/Retina/towerDefense_tile246.png", 0,
    ennemy->pos.x, ennemy->pos.y);
    ennemy->full_life = init_image("PNG/full_health_ennemy.png",
    0, ennemy->pos.x, ennemy->pos.y);
    ennemy->third_life = init_image("PNG/third_health_ennemy.png",
    0, ennemy->pos.x, ennemy->pos.y);
    ennemy->mid_life = init_image("PNG/mid_health_ennemy.png",
    0, ennemy->pos.x, ennemy->pos.y);
    ennemy->low_life = init_image("PNG/low_health_ennemy.png",
    0, ennemy->pos.x, ennemy->pos.y);
    ennemy->no_life = init_image("PNG/no_health_ennemy.png",
    0, ennemy->pos.x, ennemy->pos.y);
}

ennemy_t *create_ennemy(int hp, int ground, defender_t *defender, int y_pos)
{
    ennemy_t *ennemy = malloc(sizeof(ennemy_t));

    if (ennemy == NULL)
        return (NULL);
    ennemy->pos = find_initial_ennemy_pos(defender, y_pos);
    ennemy->ground = ground;
    ennemy->health = hp;
    ennemy->init_health = hp;
    ennemy->shoot_length = 3;
    ennemy->shoot = 0;
    ennemy->sprite_list = malloc(sizeof(sprite_list_t));
    if (ennemy->sprite_list == NULL)
        return (NULL);
    ennemy->sprite_list->next = NULL;
    ennemy->sprite_list->prev = NULL;
    add_images(ennemy);
    return (ennemy);
}