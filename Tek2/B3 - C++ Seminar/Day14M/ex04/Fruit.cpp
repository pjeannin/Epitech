/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD14M-pierre.jeannin
** File description:
** Fruit
*/

#include "Fruit.hpp"

Fruit::Fruit() : _name("Fruit"), _vitamins(0)
{
}

Fruit::Fruit(const std::string &name, int vitamines) : _name(name), _vitamins(vitamines)
{
}

Fruit::~Fruit()
{
}

const std::string &Fruit::getName() const
{
    if (_vitamins == 0 && _name == "lemon")
        return ("rotten lemon");
    return (_name);
}

int Fruit::getVitamins() const { return (_vitamins); }

void Fruit::setVitamin(int quantity) { _vitamins = quantity; }