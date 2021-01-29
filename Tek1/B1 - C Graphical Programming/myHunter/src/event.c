/*
** EPITECH PROJECT, 2019
** event.c
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

void __screen_zero_event(sfRenderWindow *window, sfEvent event, game_t *game)
{
    if ((event.mouseButton.x >= 185 && event.mouseButton.x <= 625) &&
        (event.mouseButton.y >= 690 && event.mouseButton.y <= 830))
        game->screen = 2;
    if ((event.mouseButton.x >= 1260 && event.mouseButton.x <= 1750) &&
        (event.mouseButton.y >= 720 && event.mouseButton.y <= 845))
        game->screen = 1;
    if ((event.mouseButton.x >= 1700 && event.mouseButton.x <= 1860) &&
        (event.mouseButton.y >= 42 && event.mouseButton.y <= 122))
        sfRenderWindow_close(window);
}

void screen_zero_event(sfRenderWindow *window, sfEvent event, game_t *game)
{
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtMouseButtonReleased &&
                event.mouseButton.button == sfMouseLeft)
            __screen_zero_event(window, event, game);
}

void __screen_one_event(sfRenderWindow *window, sfEvent event, game_t *game)
{
    if ((event.mouseButton.x >= 1575 && event.mouseButton.x <= 1825) &&
        (event.mouseButton.y >= 950 && event.mouseButton.y <= 1020))
        game->screen = 0;
    if ((event.mouseButton.x >= 1700 && event.mouseButton.x <= 1860) &&
        (event.mouseButton.y >= 42 && event.mouseButton.y <= 122))
        sfRenderWindow_close(window);
}

void screen_one_event(sfRenderWindow *window, sfEvent event, game_t *game)
{
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtMouseButtonReleased &&
            event.mouseButton.button == sfMouseLeft)
            __screen_one_event(window, event, game);
}