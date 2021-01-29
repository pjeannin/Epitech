/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void init_frame_buffer(game_t *game_struct)
{
    srand(time(NULL));
    for (int i = 0; i < WINDOW_HEIGHT * WINDOW_WIDTH * 4; ++i) {
        game_struct->frame_buffer[i] = 0;
        if (rand() % 10 == 0 && i % 4 == 0)
            set(&game_struct->frame_buffer[i], 187, 211, 250);
    }
}