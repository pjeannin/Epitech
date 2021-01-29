/*
** EPITECH PROJECT, 2019
** big_screen.c
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

void case_bigscreen(sfRenderWindow *bigscreen, sfEvent event, game_t *game,
                    target_t *target)
{
    switch (game->screen) {
        case 0: {
            screen_zero(bigscreen, event, game, target->bird);
            break;
        } case 1: {
            screen_one(bigscreen, event, game);
            break;
        } case 2: {
            screen_two(bigscreen, event, game, target);
            break;
        } case 3: {
            screen_three(bigscreen, event, game, target->bird);
            break;
        } case 4: {
            screen_four(bigscreen, event,game, target->bird);
            break;
        } case 5: {
            screen_five(bigscreen, event, game, target->devil_bird);
        }
    }
}

void main(void)
{
    sfRenderWindow *bigscreen = creat_window(1920, 1080, "My Hunter");
    target_t *target = init_target();
    sfText *exit = set_text("EXIT", 100, 1700, 20);
    sfEvent event;
    game_t *game = malloc(sizeof(game_t));

    init_game_struct(game, 'b');
    while (sfRenderWindow_isOpen(bigscreen)) {
        case_bigscreen(bigscreen, event, game, target);
        sfRenderWindow_drawText(bigscreen, exit, sfFalse);
        sfRenderWindow_display(bigscreen);
    }
    free_game(game);
    free_target(target);
    sfText_destroy(exit);
}