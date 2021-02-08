/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-pierre.jeannin
** File description:
** Supply
*/

#include "Supply.hpp"

Supply::Supply(Types type, size_t amount) : _type(type), _amount(amount), _werks(nullptr), _currentDroid(0)
{
}

Supply::Supply(Types type, size_t amount, Droid **werks) : _type(type), _amount(amount), _werks(werks), _currentDroid(0)
{
}

Supply::~Supply()
{
    if (_type == Werk)
        for (int i = 0; i < 5; ++i)
            if (_werks[i])
                delete _werks[i];
}

Supply::Types Supply::getType() const { return (_type); }

Droid *&Supply::operator*() const
{
    if (_type == Werk)
        return (_werks[_currentDroid]);
}

Supply *Supply::operator++()
{
    if (_type == Werk)
        _currentDroid = ++_currentDroid % _amount;

    return (this);
}

Supply *Supply::operator--()
{
    if (_type == Werk)
        _currentDroid = _currentDroid > 0 ? --_currentDroid : _amount - 1;

    return (this);
}

Supply *Supply::operator->()
{
    return (this);
}

void Supply::operator!()
{
    if (_type == Werk)
        for (int i = 0; i < _amount; ++i)
            if (_werks[i])
                delete _werks[i];
    _werks = nullptr;
    _amount = 0;
}

bool Supply::operator==(Types type) const { return(_type == type); }

bool Supply::operator!=(Types type) const { return(!operator==(type)); }