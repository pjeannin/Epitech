/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07A-pierre.jeannin
** File description:
** KreogCom
*/

#include <iostream>
#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial, KreogCom *next) : _serial(serial), _x(x), _y(y), _next(next)
{
    std::cout << "KreogCom " << serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    if (_serial != 0)
        std::cout << "KreogCom " << _serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    _next = new KreogCom(x, y, serial, _next);
}

KreogCom *KreogCom::getCom()
{
    return (_next);
}

void KreogCom::removeCom()
{
    KreogCom *tmp = _next;
    size_t serial = 5624524525625225;

    if (_next) {
        serial = _next->_serial;
        _next = _next->_next;
        delete tmp;
    }
    if (serial == 0)
        _next->removeCom();
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << _serial << " currently at " << _x << " " << _y << std::endl;
}

void KreogCom::locateSquad() const
{
    KreogCom *tmp = _next;

    if (tmp) {
        while (tmp->_next) {
            tmp->ping();
            tmp = tmp->_next;
        }
        tmp->ping();
    }
    ping();
}