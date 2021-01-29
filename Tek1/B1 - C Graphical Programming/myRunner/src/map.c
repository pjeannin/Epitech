/*
** EPITECH PROJECT, 2020
** map.c
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

void move_map(game_t *game)
{
    game->map = move_beginning(game->map);
    while (game->map->next) {
        (game->map->element)->pos.x -= 8;
        sfSprite_setPosition((game->map->element)->sprite,
        (game->map->element)->pos);
        game-> map = game->map->next;
    }
}

void disp_map(sfRenderWindow *window, map_list_t *map)
{
    map = move_beginning(map);
    while (map->next) {
        sfRenderWindow_drawSprite(window, (map->element)->sprite, sfFalse);
        map = map->next;
    }
}

void free_map(game_t *game)
{
    game->map = move_beginning(game->map);
    game->map = game->map->next;
    while (game->map) {
        free_image(game->map->element);
        game->map = game->map->next;
    }
    free(game->map);
}