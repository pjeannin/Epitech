/*
** EPITECH PROJECT, 2020
** sfvectorf.c
** File description:
** sfvectorf
*/

#include <SFML/Graphics/RenderWindow.h>

sfVector2f create_sfvector2f(int nb1, int nb2)
{
    sfVector2f vector;

    vector.x = nb1;
    vector.y = nb2;
    return (vector);
}