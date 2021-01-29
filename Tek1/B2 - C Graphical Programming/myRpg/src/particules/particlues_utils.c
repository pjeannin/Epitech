/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include "my_rpg.h"

void set(sfUint8 *pixel, sfUint8 red, sfUint8 green, sfUint8 blue)
{
    pixel[R] = red;
    pixel[G] = green;
    pixel[B] = blue;
    pixel[A] = 255;
}

void reset(sfUint8 *pixel)
{
    pixel[R] = 0;
    pixel[G] = 0;
    pixel[B] = 0;
    pixel[A] = 0;
}

int check(sfUint8 *pixel, sfUint8 red, sfUint8 green, sfUint8 blue)
{
    return (pixel[R] == red && pixel[G] == green && pixel[B] == blue);
}

void copy(sfUint8 *from, sfUint8 *to)
{
    to[R] = from[R];
    to[G] = from[G];
    to[B] = from[B];
    to[A] = from[A];
}