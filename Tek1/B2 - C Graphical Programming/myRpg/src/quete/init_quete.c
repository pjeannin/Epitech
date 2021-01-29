/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** play_game
*/

#include "my_rpg.h"

void init_quete(game_t *game_struct)
{
    game_struct->need_to_display_quete = 0;
    game_struct->quete[0].done = 0;
    game_struct->quete[0].sprite = sfSprite_create();
    sfSprite_setTexture(game_struct->quete[0].sprite,
    sfTexture_createFromFile("ressources/quest/quest1.png", NULL), sfFalse);
    game_struct->quete[1].done = 0;
    game_struct->quete[1].sprite = sfSprite_create();
    sfSprite_setTexture(game_struct->quete[1].sprite,
    sfTexture_createFromFile("ressources/quest/quest2.png", NULL), sfFalse);
    game_struct->quete[2].done = 0;
    game_struct->quete[2].sprite = sfSprite_create();
    sfSprite_setTexture(game_struct->quete[2].sprite,
    sfTexture_createFromFile("ressources/quest/quest3.png", NULL), sfFalse);
    game_struct->cur_quete = 0;
}