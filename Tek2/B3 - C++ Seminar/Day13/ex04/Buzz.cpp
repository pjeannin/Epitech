/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-pierre.jeannin
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &FileName) : Toy(BUZZ, name, FileName)
{
}

Buzz::Buzz(const std::string &name) : Toy(BUZZ, name, "buzz.txt")
{
}

Buzz::~Buzz()
{
}

bool Buzz::speak(const std::string talk)
{
    std::cout << "BUZZ: ";
    return (Toy::speak(talk));
}