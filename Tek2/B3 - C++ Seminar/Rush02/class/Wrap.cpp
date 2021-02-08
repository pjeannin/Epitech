/*
** EPITECH PROJECT, 2021
** CPP-RUSH2 [WSL: Ubuntu]
** File description:
** Wrap
*/

#include "Wrap.hpp"

Wrap::Wrap(const std::string &type) : Object("Wrap", type)
{
    _type = type;
    _isTaken = false;
}

Wrap::~Wrap()
{
}

void Wrap::isTaken()
{
    if (!_isTaken)
        std::cout << "whistles while working" << std::endl;
}

void Wrap::wrapMeThat(Object *object)
{
    if (_object == nullptr && object != nullptr) {
        _object = object;
        std::cout << "tuuuut tuuut tuut" << std::endl;
    } else if (_object != nullptr) {
        std::cerr << "There is already something in the Wrap." << std::endl;
    } else {
        std::cerr << "Impossible to wrap a nullptr" << std::endl;
    }
}

Object *Wrap::openMe() { return (_object); }

bool Wrap::isEmpty() const { return (_object == nullptr ? true : false); }