/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-pierre.jeannin
** File description:
** SickKoala
*/

#include <iostream>
#include <string>
#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name) : _name(name)
{
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << _name << ": Kreooogg!! I'm cuuuured!" <<std::endl;
}

void SickKoala::poke()
{
    std::cout << "Mr." << _name << ": Gooeeeeerrk!!" <<std::endl;
}

bool SickKoala::takeDrug(std::string drug)
{
    if (drug == "Mars") {
        std::cout << "Mr." << _name << ": Mars, and it kreogs!" <<std::endl;
        return (true);
    } else if (drug == "Kinder") {
        std::cout << "Mr." << _name << ": There is a toy inside!"
        <<std::endl;
        return (true);
    } else {
        std::cout << "Mr." << _name << ": Goerkreog!" <<std::endl;
        return (false);
    }
}


void SickKoala::overDrive(std::string sentence)
{
    size_t pos = 0;

    while ((pos = sentence.find("Kreog!", 0)) != -1)
        sentence.replace(pos, ((std::string)"Kreog!").size(), "1337!");
    std::cout << "Mr." << _name << ": " << sentence <<std::endl;
}

std::string SickKoala::getName()
{
    return (_name);
}