/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

static sfVector2i change_pos(game_t *game_struct)
{
    sfVector2i pos = {0, 0};

    switch (game_struct->map->anim) {
        case 1:
            pos.y -= MAP_SPEED;
            break;
        case 2:
            pos.x += MAP_SPEED;
            break;
        case 3:
            pos.x -= MAP_SPEED;
            break;
        case 4:
            pos.y += MAP_SPEED;
            break;
        default:
            break;
    }
    return (pos);
}

static void move_framebuffer(game_t *game_struct, sfUint8 *buffer, size_t i)
{
    sfVector2i pos  = {0, 0};
    if (i < 4 && i > WINDOW_WIDTH * WINDOW_HEIGHT * 4 - (MAP_SPEED + 2)
    * WINDOW_WIDTH * 4)
        return;
    pos = change_pos(game_struct);
    if (i + pos.x * 4 + pos.y * 4 * WINDOW_WIDTH >= WINDOW_WIDTH * WINDOW_HEIGHT
    * 4)
        return;
    copy(buffer, &game_struct->frame_buffer[i + pos.x * 4 + pos.y * 4 *
    WINDOW_WIDTH]);
    reset(buffer);
}

static void update_particules_end(game_t *game_struct, size_t i)
{
    if (game_struct->frame_buffer[i + A] > 4) {
        game_struct->frame_buffer[i + A] -= 1;
        if (i > WINDOW_WIDTH * 4)
            copy(&game_struct->frame_buffer[i],
            &game_struct->frame_buffer[i + (rand() % 2 - 1) * 4 -
            WINDOW_WIDTH * 4]);
        reset(&game_struct->frame_buffer[i]);
    }
}

static void update_rain(game_t *game_struct, size_t i)
{
    static int call = 0;

    if (call++ % 4)
        return;
    if (game_struct->frame_buffer[i + A] > 10) {
        if (i < WINDOW_WIDTH * WINDOW_HEIGHT * 4 - WINDOW_WIDTH * 8
        && game_struct->frame_buffer[i + A] == 255)
            copy(&game_struct->frame_buffer[i],
            &game_struct->frame_buffer[i + 3 * WINDOW_WIDTH * 4 - 8]);
        game_struct->frame_buffer[i + A] -= 10;
    } else
        reset(&game_struct->frame_buffer[i]);
}

void update_particules(game_t *game_struct)
{
    static int call = 0;

    if (!call++ % 10)
        return;
    for (size_t i = 0; i < WINDOW_HEIGHT * WINDOW_WIDTH * 4; i += 4)
        if (check(&game_struct->frame_buffer[i], 255, 136, 25))
            update_particules_end(game_struct, i);
        else if (check(&game_struct->frame_buffer[i], 187, 211, 250))
            update_rain(game_struct, i);
    for (size_t i = 0; i < WINDOW_HEIGHT * WINDOW_WIDTH * 4; i += 4) {
        if (game_struct->map->anim) {
            if (!check(&game_struct->frame_buffer[i], 0, 0, 0)
            && !check(&game_struct->frame_buffer[i], 187, 211, 250))
                move_framebuffer(game_struct, &game_struct->frame_buffer[i], i);
        }
    }
}