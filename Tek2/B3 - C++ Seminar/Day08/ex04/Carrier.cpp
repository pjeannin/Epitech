/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-pierre.jeannin
** File description:
** Carrier
*/

#include "Carrier.hpp"

Carrier::Carrier(std::string id) : _id(id), _energy(300), _attack(100), _toughness(90)
{
    _droids = new Droid *[5];
    for (int i = 0; i < 5; ++i)
        _droids[i] = nullptr;
}

Carrier::~Carrier()
{
    for (int i = 0; i < 5; ++i)
        if (_droids[i])
            delete _droids[i];
}

void Carrier::setId(std::string id) { _id = id; }

void Carrier::setEnergy(size_t energy) { if (energy > 100) _energy = 100; else _energy = energy; }

std::string Carrier::getId() const { return (_id); }

size_t Carrier::getEnergy() const { return (_energy); }

size_t Carrier::getAttack() const { return (_attack); }

size_t Carrier::getToughness() const { return (_toughness); }

size_t Carrier::getSpeed() const { return (numberOfDroids() != 0 ? 100 - 10 * numberOfDroids() : 0); }

Carrier &Carrier::operator<<(Droid *&droid)
{
    for (int i = 0; i < 5; ++i)
        if (!_droids[i]) {
            _droids[i] = droid;
            droid = 0;
            return (*this);
        }

    return (*this);
}

Carrier &Carrier::operator>>(Droid *&droid)
{
    for (int i = 0; i < 5; ++i)
        if (_droids[i]) {
            droid = _droids[i];
            _droids[i] = 0;
            return (*this);
        }

    return (*this);
}

Droid *&Carrier::operator[](int index) const { return (_droids[index]); }

Carrier &Carrier::operator~() { return (*this); }

int Carrier::numberOfDroids() const
{
    int number = 0;

    for (int i = 0; i < 5; ++i)
        if (_droids[i])
            ++number;

    return (number);
}

bool Carrier::operator()(int x, int y)
{
    int energyCost = (std::abs(x) + std::abs(y)) * (10 + numberOfDroids());

    if (!(getSpeed() == 0) && _energy >= energyCost) {
        _energy -= energyCost;
        return (true);
    }

    return (false);
}

Carrier &Carrier::operator<<(size_t &energy)
{
    if (_energy + energy <= 600) {
        _energy += energy;
        energy = 0;
    } else {
        energy = 600 - _energy;
        _energy = 600;
    }

    return (*this);
}

std::ostream &operator<<(std::ostream &stream, const Carrier& carrier)
{
    stream << "Carrier '" << carrier.getId() << "' Droid(s) on-board:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        stream << "[" << i << "] : ";
        if (carrier[i])
            stream << *(carrier[i]) << std::endl;
        else
            stream << "Free" << std::endl;
    }
    stream << "Speed : " << carrier.getSpeed() << ", Energy " << carrier.getEnergy();

    return (stream);
}