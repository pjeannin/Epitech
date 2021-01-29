/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

static void init_object(game_t *game_struct)
{
    for (int i = 1; i < 4; ++i) {
        game_struct->object_list[i].sprite = sfSprite_create();
        sfSprite_setTexture(game_struct->object_list[i].sprite,
        sfTexture_createFromFile("ressources/inventaire/potion.png", NULL),
        sfFalse);
        sfSprite_setScale(game_struct->object_list[i].sprite,
        (sfVector2f){0.1, 0.1});
        sfSprite_setPosition(game_struct->object_list[i].sprite,
        game_struct->object_list[i].pos);
    }
}

void init_object_list(game_t *game_struct)
{
    for (int i = 0; i < 4; ++i) {
        game_struct->object_list[i].istake = 0;
        game_struct->object_list[i].isused = 0;
    }
    game_struct->object_list[1].pos = (sfVector2f){-650, -700};
    game_struct->object_list[2].pos = (sfVector2f){2000, 1240};
    game_struct->object_list[3].pos = (sfVector2f){-1500, 2000};
    game_struct->object_list[0].pos = (sfVector2f){-650, -490};
    game_struct->object_list[0].sprite = sfSprite_create();
    sfSprite_setTexture(game_struct->object_list[0].sprite,
    sfTexture_createFromFile("ressources/inventaire/dague.png", NULL), sfFalse);
    sfSprite_setPosition(game_struct->object_list[0].sprite,
    game_struct->object_list[0].pos);
    init_object(game_struct);
}
