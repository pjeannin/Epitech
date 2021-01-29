/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void add_particules(game_t *game_struct, int xn, int yn)
{
    set(&game_struct->frame_buffer[(yn) * WINDOW_WIDTH * 4 + (xn) * 4],
    255, 136, 25);
    set(&game_struct->frame_buffer[(yn) * WINDOW_WIDTH * 4 + (xn + 1) * 4],
    255, 136, 25);
    set(&game_struct->frame_buffer[(yn) * WINDOW_WIDTH * 4 + (xn + 2) * 4],
    255, 136, 25);
    set(&game_struct->frame_buffer[(yn + 1) * WINDOW_WIDTH * 4 + (xn) * 4],
    255, 136, 25);
    set(&game_struct->frame_buffer[(yn + 1) * WINDOW_WIDTH * 4 + (xn + 1) * 4],
    255, 136, 25);
    set(&game_struct->frame_buffer[(yn + 1) * WINDOW_WIDTH * 4 + (xn + 2) * 4],
    255, 136, 25);
    set(&game_struct->frame_buffer[(yn + 2) * WINDOW_WIDTH * 4 + (xn) * 4], 255,
    136, 25);
    set(&game_struct->frame_buffer[(yn + 2) * WINDOW_WIDTH * 4 + (xn + 1) * 4],
    255, 136, 25);
    set(&game_struct->frame_buffer[(yn + 2) * WINDOW_WIDTH * 4 + (xn + 2) * 4],
    255, 136, 25);
}

void create_partiules(game_t *game_struct, int x, int y)
{
    int xn = 0;
    int yn = 0;

    for (int i = 0; i < 20; ++i) {
        xn = x + rand() % 100;
        yn = y - rand() % 50;
        add_particules(game_struct, xn, yn);
        }
}

void create_rain(game_t *game_struct)
{
    static int call = 0;

    if (call++ % 2)
        return;
    set(&game_struct->frame_buffer[rand() % WINDOW_WIDTH * 4], 187, 211, 250);
}