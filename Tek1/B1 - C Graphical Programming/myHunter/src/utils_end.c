/*
** EPITECH PROJECT, 2019
** utils_end.c
** File description:
** my_hunter
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Window/Event.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "my_hunter.h"

void move(picture_t *image, game_t *game)
{
    srand(time(NULL));
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(image->clock)) > 50) {
        sfClock_restart(image->clock);
        if ((image->size)->left == 220)
            (image->size)->left = 0;
        else
            (image->size)->left += 110;
        image->texture = sfTexture_createFromFile(image->name, image->size);
        if (game->screen == 3 || game->screen == 5)
            pos_bird(image, game);
        if (game->screen == 0) {
            (image->pos).x = 905;
            (image->pos).y = 485;
        }
        sfSprite_setPosition(image->sprite, image->pos);
        sfSprite_setTexture(image->sprite, image->texture, sfFalse);
    }
}

sfText *set_text(char *str, int size, int x, int y)
{
    sfText *text = sfText_create();
    sfFont *angrybirds_font = sfFont_createFromFile("font/angrybirds.ttf");
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    sfText_setString(text, str);
    sfText_setFont(text, angrybirds_font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    return (text);
}

void free_game(game_t *game)
{
    
    //sfMusic_destroy(game->back_music);
    //sfMusic_destroy(game->shoot);
    sfClock_destroy(game->clock);
}

void pos_bird(picture_t *bird, game_t *game)
{
    int y_mov;

    y_mov = rand() % 50;
    if ((rand() % 20) < 10)
        y_mov *= -1;
    (bird->pos).y += y_mov;
    if ((bird->pos).y > 700)
        (bird->pos).y = 700;
    if ((bird->pos).y < 200)
        (bird->pos).y = 200;
    if ((bird->pos).x < 1890)
        (bird->pos).x += 30 * game->level;
    else
        (bird->pos).x = 0;
}