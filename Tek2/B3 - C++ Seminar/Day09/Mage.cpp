/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD09-pierre.jeannin
** File description:
** Mage
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level)
{
    Range = CLOSE;
    _name = name;
    _level = level;
    _pv = _pvDefault;
    _power = _powerDefault;
    _race = "Gnome";
    _strength = _strengthDefault;
    _stamina = _staminaDefault;
    _intelligence = _intelligenceDefault;
    _spirit = _spiritDefault;
    _agility = _agilityDefault;
    std::cout << _name << " Created" << std::endl;
    std::cout << _name << " teleported" << std::endl;
}

Mage::Mage()
{
}

Mage::~Mage()
{
}

int Mage::CloseAttack()
{
    if (!(_power >= 10)) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    } else if (!(Range == CLOSE))
        return (0);
    _power -= 10;
    Range = RANGE;
    std::cout << _name << " blinks" << std::endl;

    return (0);
}

int Mage::RangeAttack()
{
    if (!(_power >= 25)) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    }
    _power -= 25;
    std::cout << _name << " launches a fire ball" << std::endl;

    return (20 + _spirit);
}

void Mage::RestorePower()
{
    if (_power + 50 + _intelligence < 100)
        _power += 50 + _intelligence;
    else
        _power = 100;
    std::cout << _name << " takes a mana potion" << std::endl;
}