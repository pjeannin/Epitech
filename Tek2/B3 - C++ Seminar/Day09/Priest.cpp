/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD09-pierre.jeannin
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int level)
{
    Range = CLOSE;
    _name = name;
    _level = level;
    _pv = _pvDefault;
    _power = _powerDefault;
    _race = "Orc";
    _strength = _strengthDefault;
    _stamina = _staminaDefault;
    _intelligence = _intelligenceDefault;
    _spirit = _spiritDefault;
    _agility = _agilityDefault;
    std::cout << _name << " Created" << std::endl;
    std::cout << _name << " teleported" << std::endl;
    std::cout << _name << " enters in the order" << std::endl;
}

Priest::Priest()
{
}

Priest::~Priest()
{
}

int Priest::CloseAttack()
{
    if (!(_power >= 10)) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    } else if (!(Range == CLOSE))
        return (0);
    _power -= 10;
    Range = RANGE;
    std::cout << _name << " uses a spirit explosion" << std::endl;

    return (10 + _spirit);
}

void Priest::Heal()
{
    if (!(_power >= 10))
        return;
    if (_pv + 70 < 100)
        _pv += 70;
    else
        _pv = 100;
    _power -= 10;
    std::cout << _name << " casts a little heal spell" << std::endl;
}