/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-pierre.jeannin
** File description:
** KoalaDoctorList
*/

#include <string>
#include <iostream>
#include "KoalaDoctor.hpp"
#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *doctor) : _doctor(doctor),
_next(NULL)
{
}

KoalaDoctorList::KoalaDoctorList() : _doctor(NULL), _next(NULL)
{
}

KoalaDoctorList::~KoalaDoctorList()
{
}

bool KoalaDoctorList::isEnd()
{
    if (_next)
        return (false);

    return (true);
}

void KoalaDoctorList::append(KoalaDoctorList *new_node)
{
    KoalaDoctorList *tmp = this;

    while (tmp->_next)
        tmp = tmp->_next;
    tmp->_next = new_node;
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string name)
{
    KoalaDoctorList *tmp = this;

    while (tmp->_next && tmp->_doctor->getName() != name)
        tmp = tmp->_next;
    if (tmp->_doctor->getName() != name)
        return (tmp->_doctor);

    return (NULL);
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *to_remove)
{
    KoalaDoctorList *tmp = this;
    KoalaDoctorList *previous = NULL;

    if (this == to_remove)
        return (_next);
    while (tmp->_next && tmp != to_remove) {
        previous = tmp;
        tmp = tmp->_next;
    }
    previous->_next = tmp->_next;

    return (this);
}

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string to_remove)
{
    KoalaDoctorList *tmp = this;
    KoalaDoctorList *previous = NULL;

    if (this->_doctor->getName() == to_remove)
        return (_next);
    while (tmp->_next && tmp->_doctor->getName() != to_remove) {
        previous = tmp;
        tmp = tmp->_next;
    }
    previous->_next = tmp->_next;

    return (this);
}

KoalaDoctor *KoalaDoctorList::getContent()
{
    return (_doctor);
}

void KoalaDoctorList::dump()
{
    KoalaDoctorList *tmp = this;

    std::cout << "Doctors: ";
    while (tmp->_next) {
        std::cout << (tmp->_doctor ? tmp->_doctor->getName() : "[nullptr]")
        << ", ";
        tmp = tmp->_next;
    }
    std::cout << (tmp->_doctor ? tmp->_doctor->getName() : "[nullptr]")
    << "." << std::endl;
}

KoalaDoctorList *KoalaDoctorList::getNext()
{
    return (_next);
}