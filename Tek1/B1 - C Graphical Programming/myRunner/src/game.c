/*
** EPITECH PROJECT, 2020
** game.c
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

void e_game(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct)
{
    sfMusic *jump;

    if (event.type == sfEvtMouseButtonReleased
    && event.mouseButton.button == sfMouseLeft) {
        if ((event.mouseButton.x >= 1700 && event.mouseButton.x <= 1860)
        && (event.mouseButton.y >= 42 && event.mouseButton.y <= 122))
            sfRenderWindow_close(window);
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace
    && game_struct->mario->pos.y + 229 >= find_sol(game_struct)) {
        game_struct->up = 25;
        jump = sfMusic_createFromFile("sound/jump.wav");
        sfMusic_play(jump);
    }
}

void event_game(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct)
{
    while (sfRenderWindow_pollEvent(window, &event))
        e_game(window, event, screen, game_struct);
}

void update_game(game_t *game_struct, int *screen)
{
    sfMusic *win;

    game_struct->score += 5;
    game_struct->timer = 0;
    move_background(game_struct);
    game_struct->sol = find_sol(game_struct);
    jump(game_struct);
    run(game_struct);
    move_map(game_struct);
    if (game_struct->score > 6000) {
        win = sfMusic_createFromFile("sound/win.wav");
        sfMusic_play(win);
        *screen = 5;
    }
}

void game(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct)
{
    sfMusic *lose;
    display_background(game_struct->background, window);
    if (game_struct->timer > 1000 / 40)
        update_game(game_struct, screen);
    disp_map(window, game_struct->map);
    if (check_col(game_struct->map, game_struct->mario)) {
        lose = sfMusic_createFromFile("sound/lose.wav");
        sfMusic_play(lose);
        *screen = 4;
        free_map(game_struct);
    }
    sfRenderWindow_drawSprite(window, game_struct->mario->sprite, sfFalse);
    event_game(window, event, screen, game_struct);
}