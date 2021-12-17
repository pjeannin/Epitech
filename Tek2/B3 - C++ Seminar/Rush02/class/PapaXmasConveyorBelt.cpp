/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** PapaXmasConveyorBelt
*/

#include "PapaXmasConveyorBelt.hpp"

PapaXmasConveyorBelt::PapaXmasConveyorBelt() : IConveyorBelt()
{
    _object = nullptr;
}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt()
{
}

Object *PapaXmasConveyorBelt::takeObject()
{
    Object *tmp = _object;

    if (tmp == nullptr)
        std::cerr << "There is no object on th Conveyor Belt" << std::endl;
    _object = nullptr;

    return (tmp);
}

bool PapaXmasConveyorBelt::putObject(Object *object)
{
    if (_object != nullptr) {
        std::cerr << "You have to take the object on the conveyer belt before add an other" << std::endl;
        return (false);
    } else if (object == nullptr) {
        std::cerr << "you can't add a null object on the conveyer belt";
        return (false);
    }
    _object = object;
    return (true);
}

bool PapaXmasConveyorBelt::IN()
{
    static int boxOrGidtPaper = 1;

    if (_object != nullptr) {
        std::cerr << "Can't use IN buttun with on object on the conveyer belt" << std::endl;
        return (false);
    }
    if (boxOrGidtPaper++ % 2)
        _object = new Box();
    else
        _object = new GiftPaper();
    return (true);
}

bool PapaXmasConveyorBelt::OUT()
{
    if (_object == nullptr) {
        std::cerr << "You must place a object on the conveyer blet to use the OUT button" << std::endl;
        return (false);
    }
    delete _object;
    _object = nullptr;
    return (true);
}

IConveyorBelt *createConveyorBelt() { return (new PapaXmasConveyorBelt); }