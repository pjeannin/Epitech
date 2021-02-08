/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07A-pierre.jeannin
** File description:
** KoalaBot
*/

#include <iostream>
#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial) : _serial(serial)
{
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(const Arms &arm)
{
    _arms = arm;
}

void KoalaBot::setParts(const Legs &leg)
{
    _legs = leg;
}

void KoalaBot::setParts(const Head &head)
{
    _head = head;
}

void KoalaBot::swapParts(Arms &arm)
{
    Arms tmp = _arms;

    _arms = arm;
    arm = tmp;
}

void KoalaBot::swapParts(Legs &leg)
{
    Legs tmp = _legs;

    _legs = leg;
    leg = tmp;
}

void KoalaBot::swapParts(Head &head)
{
    Head tmp = _head;

    _head = head;
    head = tmp;
}

bool KoalaBot::status() const
{
    if (_arms.isFunctional() && _legs.isFunctional() && _head.isFunctional())
        return (true);
    return (false);
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << _serial << std::endl << "\t";
    _arms.informations();
    std::cout << "\t";
    _legs.informations();
    std::cout << "\t";
    _head.informations();
}