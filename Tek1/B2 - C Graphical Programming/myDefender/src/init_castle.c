/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_castle
*/

#include "my_defender.h"

void load_health_sprite(castle_t *castle)
{
    castle->full_life = init_image("PNG/full_health_castle.png", 0, 700, 720);
    castle->third_life = init_image("PNG/third_health_castle.png", 0, 700, 720);
    castle->mid_life = init_image("PNG/mid_health_castle.png", 0, 700, 720);
    castle->low_life = init_image("PNG/low_health_castle.png", 0, 700, 720);
    castle->no_life = init_image("PNG/no_health_castle.png", 0, 700, 720);
}

castle_t *init_castle(int level)
{
    castle_t *castle = malloc(sizeof(castle_t));

    if (castle == NULL)
        return (NULL);
    if (level == 1) {
        castle->display_sprite = init_image("PNG/Tower-Defense-Castle-1.png",
        0, 700, 760);
        castle->health = 1000;
        castle->init_health = 1000;
        castle->pos = create_sfvector2f(700, 760);
    } else if (level == 2) {
        castle->display_sprite = init_image("PNG/Tower-Defense-Castle-2.png",
        0, 700, 760);
        castle->health = 2000;
        castle->init_health = 2000;
        castle->pos = create_sfvector2f(700, 760);
    }
    load_health_sprite(castle);
    return (castle);
}