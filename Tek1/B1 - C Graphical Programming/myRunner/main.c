/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** boostrap_my_runner
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

void screen_choice(sfRenderWindow *window, sfEvent event, int *screen,
game_t *game_struct)
{
    switch (*screen) {
        case 0: {
            menu(window, event, screen);
            break;
        } case 1: {
            rules(window, event, screen);
            break;
        } case 2: {
            choose_level(window, event, screen, game_struct);
            break;
        } case 3: {
            game(window, event, screen, game_struct);
            break;
        } case 4: {
            game_over(window, event, screen, game_struct);
            break;
        } case 5:
            win(window, event, screen, game_struct);
    }
}

int main(void)
{
    sfText *exit_button = set_text("exit", 100, 1700, 20);
    sfRenderWindow *window = creat_window(1902, 1080, "My_Runner");
    sfEvent event;
    int screen = 0;
    sfClock *clock = sfClock_create();
    game_t *game_struct = init_game_struct();

    while (sfRenderWindow_isOpen(window) && game_struct->map != -1) {
        game_struct->timer +=
        sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
        sfClock_restart(clock);
        screen_choice(window, event, &screen, game_struct);
        sfRenderWindow_drawText(window, exit_button, sfFalse);
        sfRenderWindow_display(window);
    }
    free_background(game_struct->background);
    sfRenderWindow_destroy(window);
    sfText_destroy(exit_button);
}