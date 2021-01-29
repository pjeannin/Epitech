/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void init_map(game_t *game_struct)
{
    sfTexture *texture = sfTexture_createFromFile("ressources/maps/map.png",
    NULL);

    game_struct->map = malloc(sizeof(map_t));
    game_struct->map->map = sfSprite_create();
    game_struct->map->anim = 0;
    sfSprite_setTexture(game_struct->map->map, texture, sfFalse);
    sfSprite_setScale(game_struct->map->map, (sfVector2f){2, 2});
    sfSprite_setPosition(game_struct->map->map, (sfVector2f){-2250, -2700});
}