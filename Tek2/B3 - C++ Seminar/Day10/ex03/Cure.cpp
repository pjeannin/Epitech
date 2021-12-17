/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** Cure
*/

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::~Cure()
{
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    AMateria::use(target);
}

AMateria *Cure::clone() const
{
    return (new Cure);
}