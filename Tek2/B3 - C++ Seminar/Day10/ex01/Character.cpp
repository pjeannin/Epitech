/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(const std::string &name) : _name(name), _AP(40), _currentWeapon(nullptr)
{
}

Character::~Character()
{
}

std::string const &Character::getName() const { return (_name); }

int Character::getAP() const { return (_AP); }

AWeapon *const &Character::getCurrentWeapon() const { return (_currentWeapon); }

void Character::recoverAP()
{
    if (_AP + 10 < 40)
        _AP += 10;
    else
        _AP = 40;
}

void Character::attack(AEnemy *enemy)
{
    if (_currentWeapon == nullptr || _currentWeapon->getAPCost() > _AP)
        return;
    std::cout << _name << " attacks " << enemy->getType() << " with a " << _currentWeapon->getName() << std::endl;
    _currentWeapon->attack();
    enemy->takeDamage(_currentWeapon->getDamage());
    _AP -= _currentWeapon->getAPCost();
    if (enemy->getHP() <= 0)
        delete enemy;
}

void Character::equip(AWeapon *weapon) { _currentWeapon = weapon; }

std::ostream &operator<<(std::ostream &stream, const Character &character)
{
    stream << character.getName() << " has " << character.getAP() << " AP and ";
    if (character.getCurrentWeapon() != nullptr)
        stream << "wields a " << character.getCurrentWeapon()->getName() << std::endl;
    else
        stream << "is unarmed" << std::endl;
    return (stream);
}