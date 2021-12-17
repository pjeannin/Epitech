/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** SuperMutant
*/

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : AEnemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me wants smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
    damage -= 3;
    AEnemy::takeDamage(damage);
}