/*
** EPITECH PROJECT, 2019
** background.c
** File description:
** my_runner
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
#include "my_runner.h"

background_t *init_background(void)
{
    background_t *back = malloc(sizeof(background_t));

    back->background = init_image("picture/background.png", 0, 0, 0);
    back->middlebis = init_image("picture/middle.png", 0, 1500, 100);
    back->middlebisbis = init_image("picture/middle.png", 0, 500, 200);
    back->middle = init_image("picture/middle.png", 0, 1000, 300);
    back->foregroundbis = init_image("picture/foreground.png", 0, 300, 600);
    back->foregroundbisbis = init_image("picture/foreground.png", 0, 1335, 620);
    back->fg = init_image("picture/foreground.png", 0, 1000, 640);
    back->fgbis = init_image("picture/foreground.png", 0, 900, 660);
    back->sol = init_image("picture/sol.png", 0, 0, 960);
    back->solbis = init_image("picture/sol.png", 0, 5760, 960);
    back->foreground = init_image("picture/foreground.png", 0, 798, 650);
    back->montain = init_image("picture/montain.png", 0, 400, 420);
    back->big_montain = init_image("picture/montain_big.png", 0, 800, 352);
    back->mmontain = init_image("picture/montain.png", 0, 100, 420);
    back->bbig_montain = init_image("picture/montain_big.png", 0, 1200, 352);
    back->mmmontain = init_image("picture/montain.png", 0, 1800, 420);
    back->bbbig_montain = init_image("picture/montain_big.png", 0, -200, 352);
    return (back);
}

void display_background(background_t *back, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, (back->background)->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, (back->middle)->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, back->montain->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, back->big_montain->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, back->mmontain->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, back->bbig_montain->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, back->mmmontain->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, back->bbbig_montain->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, (back->middlebis)->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, (back->middlebisbis)->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, (back->foreground)->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, (back->foregroundbis)->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, back->foregroundbisbis->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, back->fg->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, back->fgbis->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, (back->sol)->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, (back->solbis)->sprite, sfFalse);
}

void move_background(game_t *game_struct)
{
    move(game_struct->background->middlebisbis, -0.3);
    move(game_struct->background->middle, -0.3);
    move(game_struct->background->middlebis, -0.5);
    move(game_struct->background->foreground, -3);
    move(game_struct->background->foregroundbis, -3);
    move(game_struct->background->foregroundbisbis, -3);
    move(game_struct->background->fg, -4);
    move(game_struct->background->fgbis, -3.5);
    move(game_struct->background->sol, -8);
    move(game_struct->background->solbis, -8);
    move(game_struct->background->big_montain, -1);
    move(game_struct->background->montain, -1);
    move(game_struct->background->bbig_montain, -1);
    move(game_struct->background->mmontain, -1);
    move(game_struct->background->bbbig_montain, -1);
    move(game_struct->background->mmmontain, -1);
}

void free_background(background_t *back)
{
    free_image(back->background);
    free_image(back->middle);
    free_image(back->middlebis);
    free_image(back->middlebisbis);
    free_image(back->sol);
    free_image(back->solbis);
    free_image(back->foreground);
    free_image(back->foregroundbis);
    free_image(back->foregroundbisbis);
    free_image(back->big_montain);
    free_image(back->montain);
    free_image(back->bbig_montain);
    free_image(back->mmontain);
    free_image(back->bbbig_montain);
    free_image(back->mmmontain);
    free_image(back->fg);
    free_image(back->fgbis);
}
