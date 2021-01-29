/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** player
*/

#include "SFML/Graphics.h"
#include "image.h"

#ifndef ENNEMY_H_
#define ENNEMY_H_

typedef struct ennemy_s {
    sprite_list_t *sprite_list;
    sfVector2f pos;
    int health;
    int init_health;
    picture_t *full_life;
    picture_t *third_life;
    picture_t *mid_life;
    picture_t *low_life;
    picture_t *no_life;
    int sky;
    int ground;
    int shoot_length;
    int shoot;
} ennemy_t;

typedef struct ennemy_list_s {
    struct ennemy_list_s *prev;
    struct ennemy_list_s *next;
    ennemy_t *ennemy;
} ennemy_list_t;

#endif /* !ENNEMY_H_ */