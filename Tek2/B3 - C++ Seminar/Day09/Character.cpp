/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD09-pierre.jeannin
** File description:
**  Character
*/

#include "Character.hpp"

Character::Character(const std::string &name, int level)
{
    Range = CLOSE;
    _name = name;
    _level = level;
    _pv = _pvDefault;
    _power = _powerDefault;
    _race = "Dwarf";
    _strength = _strengthDefault;
    _stamina = _staminaDefault;
    _intelligence = _intelligenceDefault;
    _spirit = _spiritDefault;
    _agility = _agilityDefault;

    std::cout << _name << " Created" << std::endl;
}

Character::Character()
{
}

Character::~Character()
{
}

const std::string &Character::getName() const { return (_name); }

int Character::getLvl() const { return (_level); }

int Character::getPv() const { return (_pv); }

int Character::getPower() const { return (_power); }

int Character::CloseAttack()
{
    if (!(_power >= 10)) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    } else if (!(Range == CLOSE))
        return (0);
    _power -= 10;
    std::cout << _name << " strikes with a wooden stick" << std::endl;

    return (10 + _strength);
}

int Character::RangeAttack()
{
    if (!(_power >= 10)) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    }
    _power -= 10;
    std::cout << _name << " tosses a stone" << std::endl;

    return (5 + _strength);
}

void Character::Heal()
{
    if (_pv + 50 < 100)
        _pv += 50;
    else
        _pv = 100;
    std::cout << _name << " takes a potion" << std::endl;
}

void Character::RestorePower()
{
    _power = 100;
    std::cout << _name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    if (_pv - damage > 0) {
        _pv -= damage;
        std::cout << _name << " takes " << damage << " damage" << std::endl;
    } else {
        _pv = 0;
        std::cout << _name << " out of combat" << std::endl;
    }
}