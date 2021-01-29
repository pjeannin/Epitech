/*
** EPITECH PROJECT, 2019
** screen.c
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

void show_viewfinder(sfRenderWindow *window, sfEvent event)
{
    picture_t *viewfinder;

    if (event.mouseMove.x) {
        viewfinder = init_image("picture/viseur.png", 0,
                event.mouseMove.x - 100, event.mouseMove.y - 100);
        sfRenderWindow_drawSprite(window, viewfinder->sprite, sfFalse);
        free_image(viewfinder);
    }
}

char *char_from_int(int nbr)
{
    int cpy = nbr;
    int len = 0;
    int i = 0;
    char *n;

    while (cpy > 0) {
        ++len;
        cpy /= 10;
    }
    if (len == 0)
        return("0");
    n = malloc(sizeof(char) * len);
    while (nbr > 0) {
        n[i] = (nbr % 10) | 48;
        ++i;
        nbr /= 10;
    }
    n[i] = '\0';
    return (n);
}

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