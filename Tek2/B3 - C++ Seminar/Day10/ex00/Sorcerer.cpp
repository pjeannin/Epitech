/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** Sorcerer
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
    std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!" << std::endl;
}

std::string  const &Sorcerer::getName() const { return (_name); }

std::string  const &Sorcerer::getTitle() const { return (_title); }

void Sorcerer::polymorph(const Victim &victim) const { victim.getPolymorphed(); }

std::ostream &operator<<(std::ostream &stream, const Sorcerer& sorcerer)
{
    return (stream << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies!" << std::endl);
}