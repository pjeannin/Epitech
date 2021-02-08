/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD07A-pierre.jeannin
** File description:
** Skat
*/

#include <iostream>
#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks) : _name(name), _stimpaks(stimPaks)
{
}

Skat::~Skat()
{
}

int &Skat::stimPaks()
{
    return (_stimpaks);
}

const std::string &Skat::name()
{
    return (_name);
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (_stimpaks < number)
        std::cout << "Don't be greedy" << std::endl;
    else {
        stock += number;
        _stimpaks -= number;
        std::cout << "Keep the change." << std::endl;
    }
}

void Skat::addStimPaks(unsigned int number)
{
    _stimpaks += number;
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
}

void Skat::useStimPaks()
{
    if (_stimpaks > 0) {
        --_stimpaks;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    } else
        std::cout << "Mediiiiiic" << std::endl;
}

void Skat::status()
{
    std::cout << "Soldier " << _name << " reporting " << _stimpaks << " stimpaks remaining sir!" << std::endl;
}