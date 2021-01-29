/*
** EPITECH PROJECT, 2020
** game_over.c
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

void e_game_over(sfRenderWindow *window, sfEvent event,
int *screen, game_t *game_struct)
{
    if ((event.mouseButton.x >= 1700 && event.mouseButton.x <= 1860) 
    && (event.mouseButton.y >= 42 && event.mouseButton.y <= 122))
        sfRenderWindow_close(window);
    if ((event.mouseButton.x >= 300 && event.mouseButton.x <= 550)
    && (event.mouseButton.y >= 680 && event.mouseButton.y <= 760)) {
        *screen = 3;
        game_struct->score = 0;
        game_struct->map = init_map_list(game_struct->map_name, game_struct);
    }
    if ((event.mouseButton.x >= 1400 && event.mouseButton.x <= 1650)
    && (event.mouseButton.y >= 680 && event.mouseButton.y <= 760)) {
        *screen = 0;
        game_struct->score = 0;
    }
}

void event_game_over(sfRenderWindow *window, sfEvent event,
int *screen, game_t *game_struct)
{
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtMouseButtonReleased
        && event.mouseButton.button == sfMouseLeft)
        e_game_over(win, event, screen, game_struct);
}

void game_over(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct)
{
    sfText *gover = set_text("GAME OVER", 250, 400, 370);
    sfText *score = set_text(char_from_int((int)game_struct->score),
    250, 740, 100);
    sfText *replay = set_text("replay", 100, 300, 680);
    sfText *home = set_text("home", 100, 1400, 680);

    display_background(game_struct->background, window);
    sfRenderWindow_drawSprite(window, game_struct->mario->sprite, sfFalse);
    sfRenderWindow_drawText(window, gover, sfFalse);
    sfRenderWindow_drawText(window, score, sfFalse);
    sfRenderWindow_drawText(window, replay, sfFalse);
    sfRenderWindow_drawText(window, home, sfFalse);
    event_game_over(window, event, screen, game_struct);
    sfText_destroy(gover);
    sfText_destroy(replay);
    sfText_destroy(home);
    sfText_destroy(score);
}