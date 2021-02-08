/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-pierre.jeannin
** File description:
** KoalaNurse
*/

#include <string>
#include <iostream>
#include <fstream>
#include "KoalaNurse.hpp"
#include "SickKoala.hpp"

KoalaNurse::KoalaNurse(int id) : _id(id), _is_working(false)
{
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << _id << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *koala)
{
    koala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::string drug = "";
    std::string koala_name;
    std::ifstream file(filename, std::ios::in);

    if (!filename.find(".report", filename.size() - 8) || !file.is_open())
        return (drug);
    koala_name = filename.substr(0, filename.size() - 7);
    getline(file, drug);
    std::cout << "Nurse " << _id << ": Kreog! Mr." << koala_name << " needs a " << drug
    << "!" << std::endl;
    file.close();

    return (drug);
}

void KoalaNurse::timeCheck()
{
    _is_working = !_is_working;
    std::cout << "Nurse " << _id << ": Time to g";
    if (_is_working)
        std::cout << "et to work!" << std::endl;
    else
        std::cout << "o home to my eucalyptus forest!" << std::endl;
}

int KoalaNurse::getID()
{
    return (_id);
}
