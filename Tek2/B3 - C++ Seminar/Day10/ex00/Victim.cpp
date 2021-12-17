/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** Victim
*/

#include "Victim.hpp"

Victim::Victim(std::string name) : _name(name)
{
    std::cout << "Some random victim called " << _name << " just popped!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
}

std::string const &Victim::getName() const { return (_name); }

void Victim::getPolymorphed() const
{
    std::cout << _name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const Victim& victim)
{
    return (stream << "I'm " << victim.getName() << " and I like otters!" << std::endl);
}