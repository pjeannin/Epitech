/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-pierre.jeannin
** File description:
** KoalaNurseList
*/

#include <iostream>
#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *nurse) : _nurse(nurse), _next(NULL)
{
}

KoalaNurseList::KoalaNurseList() : _nurse(NULL), _next(NULL)
{
}

KoalaNurseList::~KoalaNurseList()
{
}

bool KoalaNurseList::isEnd()
{
    if (_next)
        return (false);

    return (true);
}

void KoalaNurseList::append(KoalaNurseList *new_node)
{
    KoalaNurseList *tmp = this;

    while (tmp->_next)
        tmp = tmp->_next;
    tmp->_next = new_node;
}

KoalaNurse *KoalaNurseList::getFromID(int id)
{
    KoalaNurseList *tmp = this;

    while (tmp->_next && tmp->_nurse->getID() != id)
        tmp = tmp->_next;
    if (tmp->_nurse->getID() != id)
        return (tmp->_nurse);

    return (NULL);
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *to_remove)
{
    KoalaNurseList *tmp = this;
    KoalaNurseList *previous = NULL;

    if (this == to_remove)
        return (_next);
    while (tmp->_next && tmp != to_remove) {
        previous = tmp;
        tmp = tmp->_next;
    }
    previous->_next = tmp->_next;

    return (this);
}


KoalaNurseList *KoalaNurseList::removeFromID(int to_remove)
{
    KoalaNurseList *tmp = this;
    KoalaNurseList *previous = NULL;

    if (this->_nurse->getID() == to_remove)
        return (_next);
    while (tmp->_next && tmp->_nurse->getID() != to_remove) {
        previous = tmp;
        tmp = tmp->_next;
    }
    previous->_next = tmp->_next;

    return (this);
}

void KoalaNurseList::dump()
{
    KoalaNurseList *tmp = this;

    std::cout << "Nurses: ";
    while (tmp->_next) {
        if (tmp->_nurse)
            std::cout << tmp->_nurse->getID() << ", ";
        else
            std::cout << "[nullptr]" << ", ";
        tmp = tmp->_next;
    }
    if (tmp->_nurse)
        std::cout << tmp->_nurse->getID() << "." << std::endl;
    else
        std::cout << "[nullptr]" << "." << std::endl;
}

KoalaNurseList *KoalaNurseList::getNext()
{
    return (_next);
}

KoalaNurse *KoalaNurseList::getContent()
{
    return (_nurse);
}