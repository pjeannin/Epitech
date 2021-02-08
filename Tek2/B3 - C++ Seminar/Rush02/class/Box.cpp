/*
** EPITECH PROJECT, 2021
** CPP-RUSH2 [WSL: Ubuntu]
** File description:
** Box
*/

#include "Box.hpp"

Box::Box() : Object("Box", "Wrap"), Wrap("Box")
{
    _isOpen = true;
}

Box::~Box()
{
}

bool Box::getBoxState() const
{
    return _isOpen;
}

void Box::closeMe()
{
    _isOpen = false;
}

Object *Box::openMe()
{
    _isOpen = true;
    return(Wrap::openMe());
}

void Box::wrapMeThat(Object *object)
{
    Toy *toy = dynamic_cast<Toy *>(object);

    if (toy == nullptr)
        std::cerr << "A box can only wrap a toy" << std::endl;
    else if (!toy->getToyStatus())
        std::cerr << "The toy has to be taken to be wraped" << std::endl;
    else if (_isOpen)
        Wrap::wrapMeThat(object);
    else
        std::cerr << "The Box isn't open !" << std::endl;
}