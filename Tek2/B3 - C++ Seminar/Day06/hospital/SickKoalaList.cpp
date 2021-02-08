/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-pierre.jeannin
** File description:
** SickKoalaList
*/

#include <string>
#include <iostream>
#include "SickKoala.hpp"
#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *koala) : _koala(koala), _next(NULL)
{
}

SickKoalaList::SickKoalaList() : _koala(NULL), _next(NULL)
{
}

SickKoalaList::~SickKoalaList()
{
}

bool SickKoalaList::isEnd()
{
    if (_next)
        return (false);

    return (true);
}

void SickKoalaList::append(SickKoalaList *new_node)
{
    SickKoalaList *tmp = this;

    while (tmp->_next)
        tmp = tmp->_next;
    tmp->_next = new_node;
}

SickKoala *SickKoalaList::getFromName(std::string name)
{
    SickKoalaList *tmp = this;

    while (tmp->_next && tmp->_koala->getName() != name)
        tmp = tmp->_next;
    if (tmp->_koala->getName() != name)
        return (tmp->_koala);

    return (NULL);
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *to_remove)
{
    SickKoalaList *tmp = this;
    SickKoalaList *previous = NULL;

    if (this == to_remove)
        return (_next);
    while (tmp->_next && tmp != to_remove) {
        previous = tmp;
        tmp = tmp->_next;
    }
    previous->_next = tmp->_next;

    return (this);
}

SickKoalaList *SickKoalaList::removeFromName(std::string to_remove)
{
    SickKoalaList *tmp = this;
    SickKoalaList *previous = NULL;

    if (this->_koala->getName() == to_remove)
        return (_next);
    while (tmp->_next && tmp->_koala->getName() != to_remove) {
        previous = tmp;
        tmp = tmp->_next;
    }
    previous->_next = tmp->_next;

    return (this);
}

SickKoala *SickKoalaList::getContent()
{
    return (_koala);
}

SickKoalaList *SickKoalaList::getNext()
{
    return (_next);
}

void SickKoalaList::dump()
{
    SickKoalaList *tmp = this;

    std::cout << "Patients: ";
    while (tmp->_next) {
        std::cout << (tmp->_koala ? tmp->_koala->getName() : "[nullptr]")
        << ", ";
        tmp = tmp->_next;
    }
    std::cout << (tmp->_koala ? tmp->_koala->getName() : "[nullptr]")
    << "." << std::endl;
}