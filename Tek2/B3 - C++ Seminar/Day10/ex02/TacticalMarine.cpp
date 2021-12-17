/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** TacticalMarine
*/

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
    std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine &tacticalMarine)
{
    std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::~TacticalMarine()
{
    std::cout << "Aaargh..." << std::endl;
}

void TacticalMarine::battleCry() const
{
    std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack() const
{
    std::cout << "* attacks with bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const
{
    std::cout << "* attacks with chainsword *" << std::endl;
}

ISpaceMarine *TacticalMarine::clone() const { return (new TacticalMarine(*this)); }