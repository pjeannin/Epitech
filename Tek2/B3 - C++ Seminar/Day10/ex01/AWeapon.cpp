/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** AWeapon
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage) : _name(name), _damage(damage), _APcost(apcost)
{
}

AWeapon::~AWeapon()
{
}

std::string const &AWeapon::getName() const { return (_name); }

int AWeapon::getAPCost() const { return (_APcost); }

int AWeapon::getDamage() const { return (_damage);}