/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void give_life_back(game_t *game_struct, window_t *win)
{
    sfVector2i mouse_pos = (sfVector2i){win->event.mouseButton.x,
    win->event.mouseButton.y};

    if (win->event.mouseButton.type == sfEvtMouseButtonPressed
    || mouse_pos.x < 210 || mouse_pos.x > 430 || mouse_pos.y < 505
    || mouse_pos.y > 550)
        return;
    for (int i = 1; i < 4; ++i)
        if (game_struct->object_list[i].istake == 1
        && game_struct->object_list[i].isused == 0) {
            game_struct->object_list[i].isused = 1;
            game_struct->player_stats.life = (game_struct->player_stats.life <=
            50 ? game_struct->player_stats.life + 50 : 100);
            return;
        }
}