/*
** EPITECH PROJECT, 2019
** event_screen_four.c
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

void __screen_four_event(sfRenderWindow *window, sfEvent event, game_t *game,
        picture_t *bird)
{
    if ((event.mouseButton.x >= 1575 && event.mouseButton.x <= 1825) &&
        (event.mouseButton.y >= 950 && event.mouseButton.y <= 1020))
        game->screen = 0;
    if ((event.mouseButton.x >= 30 && event.mouseButton.x <= 350) &&
        (event.mouseButton.y >= 965 && event.mouseButton.y <= 1060)) 
        init_game(bird, game, game->level, window);
    if ((event.mouseButton.x >= 1700 && event.mouseButton.x <= 1860) &&
        (event.mouseButton.y >= 42 && event.mouseButton.y <= 122))
        sfRenderWindow_close(window);
}


void screen_four_event(sfRenderWindow *window, sfEvent event, game_t *game,
        picture_t *bird)
{
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtMouseButtonReleased &&
            event.mouseButton.button == sfMouseLeft)
            __screen_four_event(window, event, game, bird);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(game->clock)) > (8000)) {
        sfClock_restart(game->clock);
        game->screen = 0;
    }
}