/*
** EPITECH PROJECT, 2019
** screen_bis.c
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

void destroy_screen_four(sfText *one, sfText *two, sfText *three, sfText *four)
{
    sfText_destroy(one);
    sfText_destroy(two);
    sfText_destroy(three);
    sfText_destroy(four);
}

void screen_four(sfRenderWindow *window, sfEvent event, game_t *game,
    picture_t *bird)
{
    picture_t *background = init_image("picture/bggame.png", 0, 0, 0);
    sfText *tscore = set_text("your score", 170, 600, 300);
    sfText *score = set_text(char_from_int(game->score), 170, 900, 600);
    sfText *best_score = set_text("Best score", 200, 550, 50);
    sfText *menu = set_text("Menu", 120, 1640, 940);
    sfText *replay = set_text("Replay", 120, 30, 940);

    sfRenderWindow_drawSprite(window, background->sprite, sfFalse);
    if (game->score > game->tmp) {
        sfRenderWindow_drawText(window, best_score, sfFalse);
        game->high_score = game->score;
    }
    sfRenderWindow_drawText(window, score, sfFalse);
    sfRenderWindow_drawText(window, tscore, sfFalse);
    sfRenderWindow_drawText(window, menu, sfFalse);
    sfRenderWindow_drawText(window, replay, sfFalse);
    screen_four_event(window, event, game, bird);
    free_image(background);
    sfText_destroy(replay);
    destroy_screen_four(tscore, score, best_score, menu);
}

void screen_five(sfRenderWindow *window, sfEvent event, game_t *game,
    picture_t *bird)
{
    picture_t *background = init_image("picture/bgdevil.png", 0, 0, 0);
    sfText *thigh_score = set_text("high score :", 60, 30, 30);
    sfText *high_score = set_text(char_from_int(game->high_score), 60, 350, 30);
    sfText *tscore = set_text("score", 60, 30, 1000);
    sfText *score = set_text(char_from_int(game->score), 60, 200, 1000);

    sfRenderWindow_drawSprite(window, background->sprite, sfFalse);
    sfRenderWindow_drawText(window, high_score, sfFalse);
    sfRenderWindow_drawText(window, tscore, sfFalse);
    sfRenderWindow_drawText(window, score, sfFalse);
    sfRenderWindow_drawText(window, thigh_score, sfFalse);
    sfRenderWindow_drawSprite(window, bird->sprite, sfFalse);
    screen_three_event(window, event, game, bird);
    move(bird, game);
    sfText_destroy(thigh_score);
    sfText_destroy(high_score);
    sfText_destroy(tscore);
    sfText_destroy(score);
    free_image(background);
}