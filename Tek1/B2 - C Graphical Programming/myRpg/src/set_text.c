/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

sfText *set_text(char *str, int size, int x, int y)
{
    sfText *text = sfText_create();
    sfFont *angrybirds_font =
    sfFont_createFromFile("ressources/font/arial.ttf");
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    sfText_setString(text, str);
    sfText_setFont(text, angrybirds_font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    return (text);
}