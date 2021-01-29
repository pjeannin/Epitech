/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_image
*/

#include "image.h"

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

    if (image == NULL || area == NULL)
        return (NULL);
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