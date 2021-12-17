/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-pierre.jeannin
** File description:
** KoalaDoctor
*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "KoalaDoctor.hpp"
#include "SickKoala.hpp"

KoalaDoctor::KoalaDoctor(std::string name) : _name(name), _is_working(false)
{
    std::cout << "Dr." << _name << ": I'm Dr." << _name << "! How do you kreog?"
    << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *koala)
{
    std::ofstream file(koala->getName().append(".report"),
    std::ios::out | std::ios::trunc);
    const std::string drug_list[5] = { "Mars", "Kinder", "Crunch",
        "Maroilles", "Eucalyptus leaf"};

    std::cout << "Dr." << _name << ": So what's goerking you Mr."
    << koala->getName() << "?" << std::endl;
    koala->poke();
    file << drug_list[random() % 5];
    file.close();
}

void KoalaDoctor::timeCheck()
{
    _is_working = !_is_working;
    std::cout << "Dr." << _name << ": Time to g";
    if (_is_working)
        std::cout << "et to work!" << std::endl;
    else
        std::cout << "o home to my eucalyptus forest!" << std::endl;
}

std::string KoalaDoctor::getName()
{
    return (_name);
}