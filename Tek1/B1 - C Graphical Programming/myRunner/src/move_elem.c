/*
** EPITECH PROJECT, 2020
** move_elem.c
** File description:
** runner
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Window/Event.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Audio.h>
#include <SFML/Window/Keyboard.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_runner.h"

void move(picture_t *picture, float speed)
{
    if (sfTexture_getSize(picture->texture).x + (picture->pos).x == 0)
        if (sfTexture_getSize(picture->texture).x > 1920)
            (picture->pos).x = sfTexture_getSize(picture->texture).x - 8;
        else
            (picture->pos).x = 1920;
    else
        (picture->pos).x += speed;
    sfSprite_setPosition(picture->sprite, picture->pos);
}

void run(game_t *game_struct)
{
    game_struct->map = move_beginning(game_struct->map);
    sfClock_restart(game_struct->mario->clock);
    (game_struct->mario->size)->left += 247;
    if ((game_struct->mario->size)->left > 3950)
        (game_struct->mario->size)->left = 0;
    sfTexture_destroy(game_struct->mario->texture);
    sfSprite_destroy(game_struct->mario->sprite);
    game_struct->mario->sprite = sfSprite_create();
    game_struct->mario->texture = sfTexture_createFromFile(
        game_struct->mario->name, game_struct->mario->size);
    sfSprite_setTexture(game_struct->mario->sprite,
    game_struct->mario->texture, sfFalse);
    sfSprite_setPosition(game_struct->mario->sprite, game_struct->mario->pos);
}