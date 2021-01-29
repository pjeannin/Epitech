/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void draw_particules(game_t *game_struct, window_t *win)
{
    sfTexture *texture = sfTexture_create(WINDOW_WIDTH, WINDOW_HEIGHT);
    sfSprite *sprite = sfSprite_create();

    if (!texture || !sprite)
        exit(84);
    sfTexture_updateFromPixels(
        texture, game_struct->frame_buffer,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        0, 0
    );
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){0, 0});
    sfRenderWindow_drawSprite(win->window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}