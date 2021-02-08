/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** PapaXmasElf
*/

#include "PapaXmasElf.hpp"

PapaXmasElf::PapaXmasElf(const std::string name) : IElf()
{
    _name = name;
    _conveyerBelt = createConveyorBelt();
    _table = createTable();
}

PapaXmasElf::~PapaXmasElf()
{
}

void PapaXmasElf::wrap(Object *object)
{
    Toy *toy = dynamic_cast<Toy *>(object);

    if (!toy) {
        std::cerr << "Elves can only wrap toys !" << std::endl;
        return;
    }
    toy->isTaken();
    _table->putObject(toy);
    _conveyerBelt->IN();
    _object = _conveyerBelt->takeObject();
    // std::cout << _object->getTitle();
    dynamic_cast<Box *>(_object)->openMe();
    dynamic_cast<Box *>(_object)->wrapMeThat(_table->takeObject(0));
    dynamic_cast<Box *>(_object)->closeMe();
    _table->putObject(_object);
    _object = nullptr;
    _conveyerBelt->IN();
    _object = _conveyerBelt->takeObject();
    dynamic_cast<GiftPaper *>(_object)->wrapMeThat(_table->takeObject(0));
    _conveyerBelt->putObject(_object);
    _object = nullptr;
    _conveyerBelt->OUT();
}