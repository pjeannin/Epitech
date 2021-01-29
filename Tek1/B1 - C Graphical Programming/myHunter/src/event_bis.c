/*
** EPITECH PROJECT, 2019
** event_bis.c
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

void __screen_two_event(sfRenderWindow *window, sfEvent event, game_t *game,
                target_t *target)
{
    if ((event.mouseButton.x >= 800 && event.mouseButton.x <= 1060) &&
        (event.mouseButton.y >= 320 && event.mouseButton.y <= 400))
        init_game(target->bird, game, 1, window);
    if ((event.mouseButton.x >= 800 && event.mouseButton.x <= 1060) &&
        (event.mouseButton.y >= 520 && event.mouseButton.y <= 600))
        init_game(target->bird, game, 2, window);
    if ((event.mouseButton.x >= 800 && event.mouseButton.x <= 1060) &&
        (event.mouseButton.y >= 720 && event.mouseButton.y <= 800))
        init_game(target->bird, game, 3, window);
    if ((event.mouseButton.x >= 720 && event.mouseButton.x <= 1150) &&
        (event.mouseButton.y >= 920 && event.mouseButton.y <= 1000))
        init_game(target->devil_bird, game, 5, window);
    if ((event.mouseButton.x >= 1700 && event.mouseButton.x <= 1860) &&
        (event.mouseButton.y >= 42 && event.mouseButton.y <= 122))
        sfRenderWindow_close(window);
}

void screen_two_event(sfRenderWindow *window, sfEvent event, game_t *game,
                target_t *target)
{
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtMouseButtonReleased &&
            event.mouseButton.button == sfMouseLeft)
            __screen_two_event(window, event, game, target);
}

void __screen_three_event(sfRenderWindow *window, sfEvent event, game_t *game,
                picture_t *bird)
{
    if ((event.mouseButton.x >= (bird->pos).x &&
        event.mouseButton.x <= ((bird->pos).x + 110)) &&
        (event.mouseButton.y >= (bird->pos).y &&
        event.mouseButton.y <= ((bird->pos).y + 110))) {
        (bird->pos).x = 0; 
        (bird->pos).y = rand() % 200 + 700;
        move(bird, game);
        sfClock_restart(bird->clock);
        ++(game->score);
        //sfMusic_setLoop(game->shoot, sfFalse);
    }
    if ((event.mouseButton.x >= 1700 && event.mouseButton.x <= 1860) &&
        (event.mouseButton.y >= 42 && event.mouseButton.y <= 122))
        sfRenderWindow_close(window);
}

void screen_three_event(sfRenderWindow *window, sfEvent event, game_t *game,
                picture_t *bird)
{
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtMouseButtonReleased &&
            event.mouseButton.button == sfMouseLeft) {
            //sfMusic_play(game->shoot);
            __screen_three_event(window, event, game, bird);
        }
    show_viewfinder(window, event);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(game->clock)) > (5000)) {
        sfWindow_setMouseCursorVisible(window, sfTrue);
        //sfMusic_play(game->back_music);
        sfClock_restart(game->clock); 
        game->screen = 4;
    }
}