/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-pierre.jeannin
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name, const std::string &FileName) : Toy(WOODY, name, FileName)
{
}

Woody::Woody(const std::string &name) : Toy(WOODY, name, "woody.txt")
{
}

Woody::~Woody()
{
}

bool Woody::speak(const std::string talk)
{
    std::cout << "WOODY: ";
    return (Toy::speak(talk));
}