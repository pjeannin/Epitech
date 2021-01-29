/*
** EPITECH PROJECT, 2020
** rules.c
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

void e_rules(sfRenderWindow *window, sfEvent event, int *screen)
{
    if ((event.mouseButton.x >= 1700 && event.mouseButton.x <= 1860)
    && (event.mouseButton.y >= 42 && event.mouseButton.y <= 122))
        sfRenderWindow_close(window);
    if ((event.mouseButton.x >= 25 && event.mouseButton.x <= 200)
    && (event.mouseButton.y >= 60 && event.mouseButton.y <= 110))
        *screen = 0;
}

void event_rules(sfRenderWindow *window, sfEvent event, int *screen)
{
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtMouseButtonReleased
        && event.mouseButton.button == sfMouseLeft)
            e_rules(window, event, screen);
}

void rules(sfRenderWindow *window, sfEvent event, int *screen)
{
    picture_t *background_menu = init_image("picture/background_menu.png",
    0, 0, 0);
    picture_t *rules_text = init_image("picture/rules.png", 0, 0, - 100);
    picture_t *title = init_image("picture/title.png", 0, 570, 50);
    sfText *back = set_text("back", 100, 20, 20);

    sfRenderWindow_drawSprite(window, background_menu->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, rules_text->sprite, sfFalse);
    sfRenderWindow_drawText(window, back, sfFalse);
    sfRenderWindow_drawSprite(window, title->sprite, sfFalse);
    event_rules(window, event, screen);
    free_image(background_menu);
    free_image(rules_text);
    free_image(title);
    sfText_destroy(back);
}