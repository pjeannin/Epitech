/*
** EPITECH PROJECT, 2020
** level.c
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

void event_part_one(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct)
{
    if ((event.mouseButton.x >= 1700 && event.mouseButton.x <= 1860)
        && (event.mouseButton.y >= 42 && event.mouseButton.y <= 122))
            sfRenderWindow_close(window);
        if ((event.mouseButton.x >= 25 && event.mouseButton.x <= 200)
        && (event.mouseButton.y >= 60 && event.mouseButton.y <= 110))
            *screen = 0;
        if ((event.mouseButton.x >= 615 && event.mouseButton.x <= 1355)
        && (event.mouseButton.y >= 215 && event.mouseButton.y <= 350)) {
            game_struct->map = init_map_list("map/level1", game_struct);
            game_struct->map_name = "map/level1";
            *screen = 3;
        }
}

void event_part_two(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct)
{
    if ((event.mouseButton.x >= 615 && event.mouseButton.x <= 1355)
    && (event.mouseButton.y >= 410 && event.mouseButton.y <= 545)) {
        game_struct->map = init_map_list("map/level2", game_struct);
        *screen = 3;
        game_struct->map_name = "map/level2";
    }
    if ((event.mouseButton.x >= 615 && event.mouseButton.x <= 1355)
    && (event.mouseButton.y >= 615 && event.mouseButton.y <= 750)) {
        game_struct->map = init_map_list("map/level3",game_struct);
        *screen = 3;
        game_struct->map_name = "map/level3";
    }
}

void event_part_three(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct)
{
    if ((event.mouseMove.x >= 615 && event.mouseMove.x <= 1355)
        && (event.mouseMove.y >= 215 && event.mouseMove.y <= 350)) {
            sfRenderWindow_drawSprite(window,
            (init_image("picture/level1_clic.png", 0, 570, 200))->sprite,
            sfFalse);
        }
        if ((event.mouseMove.x >= 615 && event.mouseMove.x <= 1355)
        && (event.mouseMove.y >= 410 && event.mouseMove.y <= 545)) {
            sfRenderWindow_drawSprite(window,
            (init_image("picture/level2_clic.png", 0, 570, 400))->sprite,
            sfFalse);
        }
        if ((event.mouseMove.x >= 615 && event.mouseMove.x <= 1355)
        && (event.mouseMove.y >= 615 && event.mouseMove.y <= 750)) {
            sfRenderWindow_drawSprite(window,
            (init_image("picture/level3_clic.png", 0, 570, 600))->sprite,
            sfFalse);
        }
}

void event_choose_level(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct)
{
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtMouseButtonReleased
        && event.mouseButton.button == sfMouseLeft) {
            event_part_one(window, event, screen, game_struct);
            event_part_two(window, event, screen, game_struct);
        }
        event_part_three(window, event, screen, game_struct);
}

void choose_level(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct)
{
    picture_t *background = init_image("picture/background_menu.png", 0, 0, 0);
    picture_t *lev1 = init_image("picture/level1.png", 0, 570, 200);
    picture_t *lev2 = init_image("picture/level2.png", 0, 570, 400);
    picture_t *lev3 = init_image("picture/level3.png", 0, 570, 600);
    sfText *back = set_text("back", 100, 20, 20);

    sfRenderWindow_drawSprite(window, background->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, lev1->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, lev2->sprite, sfFalse);
    sfRenderWindow_drawSprite(window, lev3->sprite, sfFalse);
    sfRenderWindow_drawText(window, back, sfFalse);
    free_image(background);
    free_image(lev1);
    free_image(lev2);
    free_image(lev3);
    sfText_destroy(back);
    event_choose_level(window, event, screen, game_struct);
}