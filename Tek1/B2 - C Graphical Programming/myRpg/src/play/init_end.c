/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void init_end(game_t *game_struct)
{
    game_struct->win_menu = sfSprite_create();
    sfSprite_setTexture(game_struct->win_menu,
    sfTexture_createFromFile("ressources/menu/finish.png", NULL), sfFalse);
    sfSprite_setPosition(game_struct->win_menu, (sfVector2f){640, 270});
}