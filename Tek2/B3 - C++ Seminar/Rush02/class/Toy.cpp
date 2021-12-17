/*
** EPITECH PROJECT, 2021
** rush2perso
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(const std::string &title) : Object(title, "Toy")
{
}

Toy::~Toy()
{
}

bool Toy::getToyStatus() const { return (_isTaken); }