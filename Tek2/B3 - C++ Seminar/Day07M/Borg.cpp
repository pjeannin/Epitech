/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07M-pierre.jeannin
** File description:
** Borg
*/

#include "Borg.hpp"

Borg::Ship::Ship(int weaponFrequency, short repair) : _maxWarp(9), _side(300), _home(UNICOMPLEX), _location(UNICOMPLEX), _shield(100), _weaponFrequency(weaponFrequency), _repair(repair)
{
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
}

void Borg::Ship::checkCore()
{
    std::cout << (_core->checkReactor()->isStable() ? "Everything is in order." : "Critical failure imminent.") << std::endl;
}

bool Borg::Ship::move()
{
    if (_location == _home || !_core->checkReactor()->isStable())
        return (false);
    _location = _home;

    return (true);
}

bool Borg::Ship::move(Destination d)
{
    if (_location == d || !_core->checkReactor()->isStable())
        return (false);
    _location = d;

    return (true);
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (_location == d || !_core->checkReactor()->isStable() || !(warp < _maxWarp))
        return (false);
    _location = d;

    return (true);
}

bool Borg::Ship::move(int warp)
{
    if (_location == _home || !_core->checkReactor()->isStable() || !(warp < _maxWarp))
        return (false);
    _location = _home;

    return (true);
}

int Borg::Ship::getShield()
{
    return (_shield);
}

void Borg::Ship::setShield(int shield)
{
    _shield = shield;
}

int Borg::Ship::getWeaponFrequency()
{
    return (_weaponFrequency);
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    _weaponFrequency = frequency;
}

short Borg::Ship::getRepair()
{
    return (_repair);
}

void Borg::Ship::setRepair(short repair)
{
    _repair = repair;
}

// void Borg::Ship::fire(Federation::Starfleet::Ship *target)
// {
//     target->setShield(target->getShield() - _weaponFrequency);
//     std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
// }

// void Borg::Ship::fire(Federation::Ship *target)
// {
//     target->setShield(target->getShield() - _weaponFrequency);
//     std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
// }

void Borg::Ship::repair()
{
    if (getRepair() < 0) {
        _shield = 100;
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    }
    std::cout << "Energy cells depleted , shield weakening." << std::endl;
}