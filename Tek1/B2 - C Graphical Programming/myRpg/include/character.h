/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** define
*/

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "menu.h"

typedef struct charact_s
{
    sfSprite *S_charact;
    sfTexture *T_charact;
    sfVector2f charact_pos;
    sfVector2f charact_scale;
    sfIntRect charact_rect;
    int has_shoot;
    int time;
    int anim;

} charact_t;

charact_t *charact;

void init_charact(charact_t *charact);
void draw_charact(charact_t *charact, window_t *win);
void anime_charact(charact_t *charact);

#endif