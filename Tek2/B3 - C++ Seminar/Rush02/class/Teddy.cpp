/*
** EPITECH PROJECT, 2021
** rush2perso
** File description:
** Teddy
*/

#include "Teddy.hpp"

Teddy::Teddy(const std::string &title) : Object(title, "Toy"), Toy(title)
{
}

Teddy::~Teddy()
{
}

void Teddy::isTaken()
{
    if (!_isTaken) {
        std::cout << "gra hu" << std::endl;
        _isTaken = true;
    }
};