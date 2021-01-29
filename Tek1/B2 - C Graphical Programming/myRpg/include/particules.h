/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** define
*/

#include "SFML/Graphics.h"

#ifndef PARTICULES_H_
#define PARTICULES_H_

void set(sfUint8 *pixel, sfUint8 red, sfUint8 green, sfUint8 blue);
void reset(sfUint8 *pixel);
int check(sfUint8 *pixel, sfUint8 red, sfUint8 green, sfUint8 blue);
void copy(sfUint8 *from, sfUint8 *to);

#endif /* !PARTICULES_H_ */