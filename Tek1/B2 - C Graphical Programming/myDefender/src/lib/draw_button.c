/*
** EPITECH PROJECT, 2020
** draw_button.c
** File description:
** draw_button
*/

#include "button.h"

void draw_button(button_t *button, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, button->button, sfFalse);
    sfRenderWindow_drawText(window, button->text, sfFalse);
}