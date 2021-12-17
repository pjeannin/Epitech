/*
** EPITECH PROJECT, 2021
** CPP-RUSH2 [WSL: Ubuntu]
** File description:
** ConveyorBeltRand
*/

#include "ConveyorBeltRand.hpp"

ConveyorBeltRand::ConveyorBeltRand()
{
}

ConveyorBeltRand::~ConveyorBeltRand()
{
}

bool ConveyorBeltRand::IN()
{
    if (_object != nullptr) {
        std::cerr << "e speex 'n'XML" << std::endl;
        return (false);
    }
    if (random() % 2)
        _object = new Box();
    else
        _object = new GiftPaper();
    return (true);
}