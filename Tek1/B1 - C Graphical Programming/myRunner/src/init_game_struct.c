/*
** EPITECH PROJECT, 2020
** init_game_struc.c
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

game_t *init_game_struct(void)
{
    game_t *init = malloc(sizeof(game_t));

    init->timer = 0;
    init->mario = init_image("picture/mariorun.png", 250, 300, 747);
    init->background = init_background();
    init->up = 0;
    init->sol = 0;
    init->score = 0;
    return (init);
}