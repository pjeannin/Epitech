/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** Squad
*/

#include "Squad.hpp"

Squad::Squad()
{
}

Squad::Squad(const Squad &squad)
{
    for (int i = 0; i < squad.getCount(); ++i)
        _squad.push_back(squad._squad[i]->clone());
}

Squad::~Squad()
{
    for (int i = 0; i < _squad.size(); ++i)
        delete _squad[i];
}

int Squad::getCount() const { return (_squad.size()); }

ISpaceMarine *Squad::getUnit(int position)
{
    if (position >= _squad.size())
        return (nullptr);
    return (_squad[position]);
}

int Squad::push(ISpaceMarine *newISpaceMarine)
{
    if (newISpaceMarine == nullptr)
        return (_squad.size());
    for (int i = 0; i < _squad.size(); ++i)
        if (_squad[i] == newISpaceMarine)
            return (_squad.size());
    _squad.push_back(newISpaceMarine);

    return (_squad.size());
}

Squad &Squad::operator=(const Squad &squad)
{
    for (int i = 0; i < _squad.size(); ++i)
        delete _squad[i];
    for (int i = 0; i < squad.getCount(); ++i)
        _squad.push_back(squad._squad[i]->clone());

    return (*this);
}