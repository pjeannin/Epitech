/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(const std::string name) : _name(name)
{
    for (int i = 0; i < 4; ++i)
        _inventory[i] = nullptr;
}

Character::Character(Character &character)
{
    _name = character._name;
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i])
            delete _inventory[i];
        _inventory[i] = nullptr;
        if (character._inventory[i])
            _inventory[i] = character._inventory[i];
    }
}

Character::~Character()
{
}

const std::string &Character::getName() const { return (_name); }

void Character::equip(AMateria *materia)
{
    for (int i = 0; i < 4; ++i)
        if (_inventory[i] == nullptr) {
            _inventory[i] = materia;
            return;
        }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3)
        _inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx <= 3 && _inventory[idx] != nullptr)
        _inventory[idx]->use(target);
}

Character &Character::operator=(Character &character)
{
    _name = character._name;
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i])
            delete _inventory[i];
        _inventory[i] = nullptr;
        if (character._inventory[i])
            _inventory[i] = character._inventory[i];
    }

    return (*this);
}