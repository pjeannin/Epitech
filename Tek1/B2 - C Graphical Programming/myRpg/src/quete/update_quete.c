/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** play_game
*/

#include "my_rpg.h"

void updtade_quete(game_t *game_struct)
{
    int done = 0;

    if (game_struct->object_list[0].istake == 2) {
        game_struct->quete[0].done = 1;
        game_struct->object_list[0].istake = 1;
        for (int i = 0; i < 4; ++i)
            game_struct->guardian[i].isalave = 1;
        game_struct->need_to_display_quete = 1;
        ++game_struct->cur_quete;
    }
    for (int i = 0; i < 4; ++i) {
        if (game_struct->quete[0].done && !game_struct->guardian[i].isalave)
            ++done;
    }
    if (done == 4) {
        game_struct->quete[1].done = 1;
        game_struct->need_to_display_quete = 1;
        game_struct->cur_quete = 2;
    } else if (game_struct->boss.life <= 0)
        game_struct->quete[2].done = 1;
}