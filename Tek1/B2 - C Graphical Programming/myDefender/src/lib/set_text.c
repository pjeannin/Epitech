/*
** EPITECH PROJECT, 2020
** set_text.c
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

sfText *set_text(char *str, int size, int x, int y)
{
    sfText *text = sfText_create();
    sfFont *angrybirds_font = sfFont_createFromFile("font/angrybirds.ttf");
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    sfText_setString(text, str);
    sfText_setFont(text, angrybirds_font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    return (text);
}