/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_defense
*/

#include "my_defender.h"

defense_t *init_def_one(int x, int y)
{
    defense_t *defense = malloc(sizeof(defense_t));

    if (defense == NULL)
        return (NULL);
    defense->sprite = init_image("PNG/Retina/towerDefense_tile249.png",
    0, x * 128, y * 128);
    defense->health = 100;
    defense->ground_attack = 1;
    defense->sky_attack = 0;
    defense->stroke = 2;
    defense->pos.x = x * 128;
    defense->pos.y = y * 128;
    defense->shoot = 0;
    return (defense);
}

defense_t *init_def_two(int x, int y)
{
    defense_t *defense = malloc(sizeof(defense_t));

    if (defense == NULL)
        return (NULL);
    defense->sprite = init_image("PNG/Retina/towerDefense_tile250.png",
    0, x * 128, y * 128);
    defense->health = 150;
    defense->ground_attack = 0;
    defense->sky_attack = 1;
    defense->stroke = 3;
    defense->pos.x = x * 128;
    defense->pos.y = y * 128;
    defense->shoot = 0;
    return (defense);
}

defense_t *create_defense(int type, int x, int y)
{
    defense_t *defense;
    defense_t *verif;

    switch (type)
    {
    case 1:
        if ((defense = init_def_one(x, y)) == NULL)
            return (NULL);
        break;
    case 2:
        if ((defense = init_def_two(x, y)) == NULL)
            return (NULL);
    default:
        break;
    }
    return (defense);
}