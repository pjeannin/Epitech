/*
** EPITECH PROJECT, 2020
** win.c
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

void win(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct)
{
    picture_t *background_menu = init_image("picture/background_menu.png",
    0, 0, 0);
    sfText *win = set_text("You win", 250, 550, 370);
    sfText *score = set_text(char_from_int((int)game_struct->score), 250,
    740, 100);
    sfText *replay = set_text("replay", 100, 300, 680);
    sfText *home = set_text("home", 100, 1400, 680);

    sfRenderWindow_drawSprite(window, background_menu->sprite, sfFalse);
    sfRenderWindow_drawText(window, score, sfFalse);
    sfRenderWindow_drawText(window, win, sfFalse);
    sfRenderWindow_drawText(window, replay, sfFalse);
    sfRenderWindow_drawText(window, home, sfFalse);
    event_game_over(window, event, screen, game_struct);
    sfText_destroy(win);
    sfText_destroy(replay);
    sfText_destroy(home);
    sfText_destroy(score);
}