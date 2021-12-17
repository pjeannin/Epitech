/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** AEnemy
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type) : _type(type), _hp(hp)
{
}

AEnemy::~AEnemy()
{
}

std::string const &AEnemy::getType() const { return (_type); }

int AEnemy::getHP() const { return (_hp); }

void AEnemy::takeDamage(int damage)
{
    if (damage < 0)
        return;
    else if (_hp - damage < 0)
        _hp = 0;
    else
        _hp -= damage;
}