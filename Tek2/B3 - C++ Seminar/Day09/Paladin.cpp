/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD09-pierre.jeannin
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level)
{
    Range = CLOSE;
    _weapon = "hammer";
    _name = name;
    _level = level;
    _pv = _pvDefault;
    _power = _powerDefault;
    _race = "Human";
    _strength = _strengthDefault;
    _stamina = _staminaDefault;
    _intelligence = _intelligenceDefault;
    _spirit = _spiritDefault;
    _agility = _agilityDefault;
    std::cout << _name << " Created" << std::endl;
    std::cout << "I'm " << _name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
    std::cout << _name << " teleported" << std::endl;
    std::cout << _name << " enters in the order" << std::endl;
    std::cout << "the light falls on " << _name << std::endl;
}

Paladin::Paladin(const std::string &name, int level, std::string weapon)
{
    Range = CLOSE;
    _weapon = weapon;
    _name = name;
    _level = level;
    _pv = _pvDefault;
    _power = _powerDefault;
    _race = "Human";
    _strength = _strengthDefault;
    _stamina = _staminaDefault;
    _intelligence = _intelligenceDefault;
    _spirit = _spiritDefault;
    _agility = _agilityDefault;
    std::cout << _name << " Created" << std::endl;
    std::cout << "the light falls on " << _name << std::endl;
}

Paladin::~Paladin()
{
}

int Paladin::CloseAttack()
{
    return (Warrior::CloseAttack());
}

void Paladin::Heal()
{
    Priest::Heal();
}

int Paladin::RangeAttack()
{
    return (Priest::RangeAttack());
}

int Paladin::Intercept()
{
    return (Warrior::RangeAttack());
}

void Paladin::RestorePower()
{
    Character::RestorePower();
}