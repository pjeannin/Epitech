/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** PapaXmasTable
*/

#include "PapaXmasTable.hpp"

PapaXmasTable::PapaXmasTable()
{
    for (int i = 0; i < 10; ++i)
        _object[i] = nullptr;
}

PapaXmasTable::~PapaXmasTable()
{
}

bool PapaXmasTable::putObject(Object *object)
{
    if (object == nullptr) {
        std::cerr << "Can't put empty object on the table" << std::endl;
        return (false);
    }
    for (int i = 0; i < 10; ++i)
        if (_object[i] == nullptr) {
            _object[i] = object;
            return (true);
        }
    std::cerr << "You can put more that 10 object on the table" << std::endl;

    return (false);
}

std::string *PapaXmasTable::look()
{
    std::string *returnTab = new std::string[10];
    int index = 0;

    for (int i = 0; i < 10; ++i)
        if (_object[i] != nullptr)
            returnTab[index++] = _object[i]->getTitle();
        else
            returnTab[index++] = nullptr;
    returnTab[index] = nullptr;

    return (returnTab);
}

Object *PapaXmasTable::takeObject(int pos)
{
    Object *tmp;

    if (pos >= 10)
        std::cerr << "The table can only store 10 element" << std::endl;
    else {
        tmp = _object[pos];
        _object[pos] = nullptr;
        return (tmp);
    }
    return (nullptr);
}

ITable *createTable() { return (new PapaXmasTable); }