/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD09-pierre.jeannin
** File description:
** Warrior
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level)
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
    _weapon = "hammer";
    std::cout << _name << " Created" << std::endl;
    std::cout << "I'm " << _name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::Warrior(const std::string &name, int level, std::string weapon)
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
    _weapon = weapon;
    std::cout << _name << " Created" << std::endl;
    std::cout << "I'm " << _name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::Warrior()
{
}

Warrior::~Warrior()
{
}

int Warrior::CloseAttack()
{
    if (!(_power >= 30)) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    } else if (!(Range == CLOSE))
        return (0);
    _power -= 30;
    std::cout << _name << " strikes with his " << _weapon << std::endl;

    return (20 + _strength);
}

int Warrior::RangeAttack()
{
    if (!(_power >= 10)) {
        std::cout << _name << " out of power" << std::endl;
        return (0);
    } else if (!(Range == RANGE))
        return (0);
    _power -= 10;
    Range = CLOSE;
    std::cout << _name << " intercepts" << std::endl;

    return (0);
}