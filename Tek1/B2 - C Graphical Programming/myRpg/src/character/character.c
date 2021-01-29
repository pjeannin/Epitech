/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** play_game
*/

#include "my_rpg.h"

void init_charact(charact_t *charact)
{
    charact->anim = 0;
    charact->time = 0;
    charact->charact_rect.top = 0;
    charact->charact_rect.left = 0;
    charact->charact_rect.width = 30;
    charact->charact_rect.height = 40;
    charact->charact_scale.x = 2.5;
    charact->charact_scale.y = 2.5;
    charact->charact_pos.x = 1920/2 - 50;
    charact->charact_pos.y = 1080/2 - 50;
    charact->has_shoot = 0;
    charact->S_charact = sfSprite_create();
    charact->T_charact =
    sfTexture_createFromFile("./ressources/character/VeroRun.png",
    NULL);
    sfSprite_setTexture(charact->S_charact, charact->T_charact, sfTrue);
    sfSprite_setScale(charact->S_charact, charact->charact_scale);
    sfSprite_setPosition(charact->S_charact, charact->charact_pos);
    sfSprite_setTextureRect(charact->S_charact, charact->charact_rect);
}

void anime_help_caract(charact_t *charact)
{
    charact->charact_rect.left += 32;
    if (charact->charact_rect.left == 128)
        charact->charact_rect.left = 0;
    sfSprite_setTextureRect(charact->S_charact, charact->charact_rect);
    charact->time = 0;
}

void anime_charact(charact_t *charact)
{
    static int call = 0;

    if (charact->anim == 1) {
        if (call++ % 3 == 0)
            anime_help_caract(charact);
        else
            charact->time++;
    }
}

void draw_charact(charact_t *charact, window_t *win)
{
    sfRenderWindow_drawSprite(win->window, charact->S_charact, NULL);
}