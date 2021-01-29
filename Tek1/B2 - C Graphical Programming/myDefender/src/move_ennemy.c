/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** intro_scene
*/

#include "my_defender.h"

void x_and_y(ennemy_t *ennemy)
{
    srand(time(NULL));
    if (rand() % 2)
        ennemy->pos.x += 3;
    else
        ennemy->pos.y += 3;
}

void x_one(ennemy_t *ennemy, int x)
{
    if (x == 1)
        ennemy->pos.x += 3;
}

void x_one_bis(ennemy_t *ennemy, int x)
{
    if (x == 2)
        ennemy->pos.x += 3;
}

void end_move_ennemy(ennemy_t *ennemy, int x, int y)
{
    if (y == 2 && x == 2)
        x_and_y(ennemy);
    else if (y == 2)
        ennemy->pos.y += 3;
    else
        x_one_bis(ennemy, x);
}

sfVector2f move_ennemy(defender_t *defender, ennemy_t *ennemy)
{
    sfVector2f ennemy_postition = create_sfvector2f((ennemy->pos.x + 64) / 128,
    (ennemy->pos.y + 64) / 128);
    int x = find_x(defender, ennemy, ennemy_postition);
    int y = find_y(defender, ennemy, ennemy_postition);

    if (y == 1 && x == 1)
        x_and_y(ennemy);
    else if (y == 1)
        ennemy->pos.y += 3;
    else
        x_one(ennemy, x);
    end_move_ennemy(ennemy, x, y);
    sfSprite_setPosition(ennemy->sprite_list->sprite->sprite, ennemy->pos);
            sfSprite_setPosition(ennemy->full_life->sprite, ennemy->pos);
            sfSprite_setPosition(ennemy->third_life->sprite, ennemy->pos);
            sfSprite_setPosition(ennemy->mid_life->sprite, ennemy->pos);
            sfSprite_setPosition(ennemy->low_life->sprite, ennemy->pos);
            sfSprite_setPosition(ennemy->no_life->sprite, ennemy->pos);
    return (ennemy->pos);
}