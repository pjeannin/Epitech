/*
** EPITECH PROJECT, 2020
** menu.c
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
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_runner.h"

void e_menu(sfRenderWindow *window, sfEvent event, int *screen)
{
    if (event.type == sfEvtMouseButtonReleased
    && event.mouseButton.button == sfMouseLeft) {
        if ((event.mouseButton.x >= 1700 && event.mouseButton.x <= 1860)
        && (event.mouseButton.y >= 42 && event.mouseButton.y <= 122))
            sfRenderWindow_close(window);
        if ((event.mouseButton.x >= 615 && event.mouseButton.x <= 1355)
        && (event.mouseButton.y >= 390 && event.mouseButton.y <= 510))
        *screen = 2;
        if ((event.mouseButton.x >= 615 && event.mouseButton.x <= 1355)
        && (event.mouseButton.y >= 580 && event.mouseButton.y <= 700))
        *screen = 1;
    }
}

void event_menu(sfRenderWindow *window, sfEvent event, int *screen)
{
    picture_t *button_one = init_image("picture/but1_clic.png", 0, 570, 380);
    picture_t *button_two = init_image("picture/but2_clic.png", 0, 570, 570);

    while (sfRenderWindow_pollEvent(window, &event)) {
        e_menu(window, event, screen);
        if ((event.mouseMove.x >= 615 && event.mouseMove.x <= 1355)
        && (event.mouseMove.y >= 390 && event.mouseMove.y <= 510))
            sfRenderWindow_drawSprite(window, button_one->sprite, sfFalse);
        else if ((event.mouseMove.x >= 615 && event.mouseMove.x <= 1355)
        && (event.mouseMove.y >= 580 && event.mouseMove.y <= 700))
            sfRenderWindow_drawSprite(window, button_two->sprite, sfFalse);
    }
    free_image(button_one);
    free_image(button_two);
}

void menu(sfRenderWindow *window, sfEvent event, int *screen)
{
    picture_t *background_menu = init_image("picture/background_menu.png",
    0, 0, 0);
    picture_t *button_one = init_image("picture/but1.png", 0, 570, 380);
    picture_t *button_two = init_image("picture/but2.png", 0, 570, 570);
    picture_t *title = init_image("picture/title.png", 0, 570, 50);

    sfRenderWindow_drawSprite(window, background_menu->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, button_one->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, button_two->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, title->sprite, sfFalse);
    event_menu(window, event, screen);
    free_image(background_menu);
    free_image(button_one);
    free_image(button_two);
    free_image(title);
}