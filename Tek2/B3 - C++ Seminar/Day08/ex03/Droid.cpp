/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-pierre.jeannin
** File description:
** Driod
*/

#include <iostream>
#include "Droid.hpp"

Droid::Droid(std::string serial) : _id(serial), _energy(50), _attack(25), _toughness(15), _status(new std::string("Standing by")), _battleData(new DroidMemory())
{
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &droid) : _id(droid._id), _energy(50), _attack(droid._attack), _toughness(droid._toughness), _status(droid._status)
{
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << _id << "' Destroyed" << std::endl;
}

void Droid::setId(std::string id) { _id = id; }

void Droid::setEnergy(size_t energy) { if (energy > 100) _energy = 100; else _energy = energy; }

void Droid::setStatus(std::string *status) { _status = status; }

std::string Droid::getId() const { return (_id); }

size_t Droid::getEnergy() const { return (_energy); }

size_t Droid::getAttack() const { return (_attack); }

size_t Droid::getToughness() const { return (_toughness); }

std::string *Droid::getStatus() const { return (_status); }

void Droid::setBattleData(DroidMemory *battleData) { _battleData = battleData; }

DroidMemory *Droid::getBattleData() const { return (_battleData); }

bool Droid::operator==(const Droid &droid) const { return (*_status == *droid._status); }

bool Droid::operator!=(const Droid &droid) const { return (!operator==(droid)); }

Droid &Droid::operator=(const Droid &droid)
{
    _id = droid._id;
    _energy = 50;
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

bool Droid::operator()(std::string *task, size_t exp)
{
    if (_energy - 10 <= 0) {
        _energy = 0;
        _status = new std::string("Battery Low");
        return (false);
    }
    _energy -= 10;
    if (*_battleData >= exp){
        _status = new std::string(*task + " - Completed!");
        *_battleData += exp / 2;
        return (true);
    }
    _status = new std::string(*task + " - Failed!");
    *_battleData += exp;

    return (false);
}

std::ostream &operator<<(std::ostream &stream, const Droid &droid) { return (stream << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy()); }