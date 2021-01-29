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

void init_game_struct(game_t *game, char size)
{
    //game->back_music = sfMusic_createFromFile("sound/background.wav");
    game->level = 0;
    game->screen = 0;
    game->high_score = 0;
    game->tmp = 0;
    game->clock = sfClock_create();
    //game->shoot = sfMusic_createFromFile("sound/shoot.wav");
    game->size = size;
    // sfMusic_play(game->back_music);
    // sfMusic_setLoop(game->back_music, sfTrue);
}

target_t *init_target(void)
{
    picture_t *bird = init_image("picture/target.png", 110, 905, 485);
    picture_t *devil_bird = init_image("picture/dtarget.png", 110, 905, 485);
    target_t *target = malloc(sizeof(target_t));

    target->bird = bird;
    target->devil_bird = devil_bird;
    return (target);
}

void free_target(target_t *target)
{
    free_image(target->bird);
    free_image(target->devil_bird);
    free(target);
}

sfRenderWindow *creat_window(unsigned int width, unsigned int height,
    char *window_name)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, window_name, sfNone, NULL);
    return (window);
}

void init_game(picture_t *bird, game_t *game, int level, sfRenderWindow *window)
{
    sfWindow_setMouseCursorVisible(window, sfFalse);
    sfClock_restart(bird->clock);
    sfClock_restart(game->clock);
    //sfMusic_pause(game->back_music);
    game->level = level;
    if (level <= 3)
        game->screen = 3;
    else
        game->screen = 5;
    game->score = 0;
    (bird->pos).x = 0; 
    (bird->pos).y = rand() % 200 + 700;
}