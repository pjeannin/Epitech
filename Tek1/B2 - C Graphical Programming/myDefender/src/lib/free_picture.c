/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** free_picture
*/

#include "image.h"

void free_picture(picture_t *pic)
{
    sfSprite_destroy(pic->sprite);
    sfTexture_destroy(pic->texture);
}