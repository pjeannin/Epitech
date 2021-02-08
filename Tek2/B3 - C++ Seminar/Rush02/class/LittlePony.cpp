/*
** EPITECH PROJECT, 2021
** rush2perso
** File description:
** LittlePony
*/

#include "LittlePony.hpp"

LittlePony::LittlePony(const std::string &title) : Object(title, "Toy"), Toy(title)
{
}

LittlePony::~LittlePony()
{
}

void LittlePony::isTaken()
{
    if (!_isTaken) {
        std::cout << "yo man" << std::endl;
        _isTaken = true;
    }
}