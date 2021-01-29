/*
** EPITECH PROJECT, 2019
** screen.c
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

void screen_zero(sfRenderWindow *window, sfEvent event, game_t *game,
    picture_t *bird)
{
    picture_t *background = init_image("picture/background.png", 0, 0, 0);

    sfRenderWindow_drawSprite(window, background->sprite, sfFalse);
    move(bird, game);
    sfRenderWindow_drawSprite(window, bird->sprite, sfFalse);
    screen_zero_event(window, event, game);
    free_image(background);
}

void screen_one(sfRenderWindow *window, sfEvent event, game_t *game)
{
    picture_t *rules = init_image("picture/rules.png", 0, 0, 0);

    sfRenderWindow_drawSprite(window, rules->sprite, sfFalse);
    screen_one_event(window, event, game);
    free_image(rules);
}

void screen_two(sfRenderWindow *window, sfEvent event, game_t *game,
    target_t *target)
{
    picture_t *background = init_image("picture/bggame.png", 0, 0, 0);
    sfText *choose_level = set_text("Choose Level", 170, 530, 100);
    sfText *lev1 = set_text("Level 1", 100, 800, 300);
    sfText *lev2 = set_text("Level 2", 100, 800, 500);
    sfText *lev3 = set_text("Level 3", 100, 800, 700);
    sfText *devil_text = set_text("Devil level", 100, 720, 900);

    sfRenderWindow_drawSprite(window, background->sprite, sfFalse);
    sfRenderWindow_drawText(window, choose_level, sfFalse);
    sfRenderWindow_drawText(window, lev1, sfFalse);
    sfRenderWindow_drawText(window, lev2, sfFalse);
    sfRenderWindow_drawText(window, lev3, sfFalse);
    sfRenderWindow_drawText(window, devil_text, sfFalse);
    sfText_destroy(lev1);
    sfText_destroy(lev2);
    sfText_destroy(lev3);
    sfText_destroy(choose_level);
    sfText_destroy(devil_text);
    screen_two_event(window, event, game, target);
    free_image(background);
}

void screen_three(sfRenderWindow *window, sfEvent event, game_t *game,
    picture_t *bird)
{
    picture_t *background = init_image("picture/bggame.png", 0, 0, 0);
    sfText *thigh_score = set_text("high score :", 60, 30, 30);
    sfText *high_score = set_text(char_from_int(game->high_score), 60, 350, 30);
    sfText *tscore = set_text("score", 60, 30, 1000);
    sfText *score = set_text(char_from_int(game->score), 60, 200, 1000);

    game->tmp = game->high_score;
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