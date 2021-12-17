/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** AMateria
*/

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : _type(type)
{
}

AMateria::~AMateria()
{
}

const std::string &AMateria::getType() const { return (_type); }

unsigned int AMateria::getXP() const { return (_xp); }

void AMateria::use(ICharacter &target) { _xp += 10; }