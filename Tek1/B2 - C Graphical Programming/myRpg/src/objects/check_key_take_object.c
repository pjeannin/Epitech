/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void
check_key_take_object(window_t *win, charact_t *charact, game_t *game_struct)
{
    for (int i = 0; i < 4; ++i)
        if (win->event.key.code == sfKeyE
        && win->event.key.type == sfEvtKeyPressed
        && charact->charact_pos.x > game_struct->object_list[i].pos.x - 200
        && charact->charact_pos.x < game_struct->object_list[i].pos.x + 200
        && charact->charact_pos.y > game_struct->object_list[i].pos.y - 200
        && charact->charact_pos.y < game_struct->object_list[i].pos.y + 200
        && !game_struct->object_list[i].istake) {
            if (i == 0)
                game_struct->object_list[i].istake = 2;
            else
                game_struct->object_list[i].istake = 1;
        }
}