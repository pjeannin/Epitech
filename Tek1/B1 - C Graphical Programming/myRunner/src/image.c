/*
** EPITECH PROJECT, 2020
** image.c
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
#include "my_runner.h"

void free_image(picture_t *image)
{
    sfTexture_destroy(image->texture);
    sfSprite_destroy(image->sprite);
    sfClock_destroy(image->clock);
    free(image->size);
}

void __init_image(picture_t *image, int size, char *filepath, sfIntRect *area)
{
    if (size != 0)
        image->texture = sfTexture_createFromFile(filepath, area);
    else
        image->texture = sfTexture_createFromFile(filepath, NULL);
    image->sprite = sfSprite_create();
}

picture_t *init_image(char *filepath, int size, int x, int y)
{
    picture_t *image = malloc(sizeof(picture_t));
    sfVector2f pos;
    sfIntRect *area = malloc(sizeof(sfIntRect));
    sfClock *clock = sfClock_create();

    image->name = filepath;
    image->clock = clock;
    area->top = 0;
    area->left = 0;
    area->width = size;
    area->height = size;
    image->size = area;
    __init_image(image, size, filepath, area);
    pos.x = x;
    pos.y = y;
    image->pos = pos;
    sfSprite_setPosition(image->sprite, image->pos);
    sfSprite_setTexture(image->sprite, image->texture, sfFalse);
    return (image);
}