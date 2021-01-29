/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void set_guardian_pos(game_t *game_struct, int guardian, sfVector2f pos)
{
    game_struct->guardian[guardian].pos = pos;
    sfSprite_setPosition(game_struct->guardian[guardian].sprite, pos);
}

static void pos_guardian(game_t *game_struct)
{
    set_guardian_pos(game_struct, 0, (sfVector2f){-2000, 300});
    set_guardian_pos(game_struct, 1, (sfVector2f){3600, 300});
    set_guardian_pos(game_struct, 2, (sfVector2f){2600, 570});
    set_guardian_pos(game_struct, 3, (sfVector2f){-1000, 570});
}

void init_guardian(game_t *game_struct)
{
    for (int i = 0; i < 4; ++i) {
        game_struct->guardian[i].life = 20;
        game_struct->guardian[i].has_shoot = 0;
        game_struct->guardian[i].damage = 20;
        game_struct->guardian[i].isalave = 0;
        game_struct->guardian[i].rect.height = 160;
        game_struct->guardian[i].rect.width = 160;
        game_struct->guardian[i].rect.top = 0;
        game_struct->guardian[i].rect.left = 0;
        game_struct->guardian[i].speed = 8;
        game_struct->guardian[i].move_side = 1;
        game_struct->guardian[i].sprite = sfSprite_create();
        sfSprite_setTexture(game_struct->guardian[i].sprite,
        sfTexture_createFromFile("ressources/character/guardian.png",
        sfFalse), sfFalse);
        sfSprite_setTextureRect(game_struct->guardian[i].sprite,
        game_struct->guardian[i].rect);
    }
    pos_guardian(game_struct);
}