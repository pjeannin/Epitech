/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** add_defense_animation
*/

#include "my_defender.h"

void add_defense_animation(sfEvent event, int new_defense, defender_t *defender)
{
    static picture_t *defense1;
    static picture_t *defense2;
    static int call = 0;
    sfVector2f pos = create_sfvector2f(event.mouseMove.x - 64,
    event.mouseMove.y - 64);

    if (call == 0) {
        defense1 = init_image("PNG/Retina/towerDefense_tile249.png", 0,
        event.mouseMove.x, event.mouseMove.y);
        defense2 = init_image("PNG/Retina/towerDefense_tile250.png", 0,
        event.mouseMove.x, event.mouseMove.y);
    }
    if (new_defense == 1) {
        sfSprite_setPosition(defense1->sprite, pos);
        sfRenderWindow_drawSprite(defender->window, defense1->sprite, sfFalse);
    }
    else {
        sfSprite_setPosition(defense2->sprite, pos);
        sfRenderWindow_drawSprite(defender->window, defense2->sprite, sfFalse);
    }
}