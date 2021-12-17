/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-pierre.jeannin
** File description:
** Driod
*/

#include <iostream>
#include "Droid.hpp"

Droid::Droid(std::string serial) : _id(serial), _energy(50), _attack(25), _toughness(15), _status(new std::string("Standing by"))
{
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &droid) : _id(droid._id), _energy(droid._energy), _attack(droid._attack), _toughness(droid._toughness), _status(droid._status)
{
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << _id << "' Destroyed" << std::endl;
}

void Droid::setId(std::string id) { _id = id; }

void Droid::setEnergy(size_t energy) { if (energy > 100 || energy < 0) return; _energy = energy; }

void Droid::setStatus(std::string *status) { _status = status; }

std::string Droid::getId() const { return (_id); }

size_t Droid::getEnergy() const { return (_energy); }

size_t Droid::getAttack() const { return (_attack); }

size_t Droid::getToughness() const { return (_toughness); }

std::string *Droid::getStatus() const { return (_status); }

bool Droid::operator==(const Droid &droid) const { return (_id == droid._id && _energy == droid._energy && _attack == droid._attack && _toughness == droid._toughness && *_status == *droid._status); }

bool Droid::operator!=(const Droid &droid) const { return (!operator==(droid)); }

Droid &Droid::operator=(const Droid &droid)
{
    _id = droid._id;
    _energy = droid._energy;
    delete _status;
    _status = new std::string(*(droid._status));

    return(*this);
}

Droid &Droid::operator<<(size_t &energy)
{
    if (_energy < 100) {
        if (energy > 100 - _energy) {
            energy -= 100 - _energy;
            _energy = 100;
        } else {
            _energy += energy;
            energy -= energy;
        }
    }

    return (*this);
}

std::ostream &operator<<(std::ostream &stream, const Droid &droid) { return (stream << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy()); }