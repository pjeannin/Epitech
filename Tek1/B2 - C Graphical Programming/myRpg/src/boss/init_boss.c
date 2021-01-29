/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void init_boss(game_t *game_struct)
{
    game_struct->boss.damage = 20;
    game_struct->boss.has_shoot = 0;
    game_struct->boss.isalave = 0;
    game_struct->boss.life = 10;
    game_struct->boss.rect.height = 200;
    game_struct->boss.rect.left = 0;
    game_struct->boss.rect.top = 0;
    game_struct->boss.rect.width = 200;
    game_struct->boss.pos = (sfVector2f){2850, -1420};
    game_struct->boss.sprite = sfSprite_create();
    sfSprite_setTexture(game_struct->boss.sprite,
    sfTexture_createFromFile("ressources/character/final_boss.png", NULL),
    sfFalse);
    sfSprite_setTextureRect(game_struct->boss.sprite, game_struct->boss.rect);
    sfSprite_setPosition(game_struct->boss.sprite, game_struct->boss.pos);
    sfSprite_setScale(game_struct->boss.sprite, (sfVector2f){2, 2});
}