/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD17-pierre.jeannin
** File description:
** Cesar
*/

#include "Cesar.hpp"

Cesar::Cesar() : _shfit(3)
{
}

Cesar::~Cesar()
{
}

void Cesar::encryptChar(char plainchar)
{
    if (isalpha(plainchar))
        plainchar = (plainchar - (plainchar > 96 ? 97 : 65) + _shfit) % 26 + (plainchar > 96 ? 97 : 65);
    std::cout << plainchar;
    _shfit = (_shfit + 1) % 26;
}

void Cesar::decryptChar(char cipherchar)
{
    if (isalpha(cipherchar))
        cipherchar = ((cipherchar - (cipherchar > 96 ? 97 : 65) - _shfit) % 26 + ((cipherchar - (cipherchar > 96 ? 97 : 65) - _shfit) % 26 < 0 ? 26 : 0)) + (cipherchar > 96 ? 97 : 65);
    std::cout << cipherchar;
    _shfit = (_shfit + 1) % 26;
}

void Cesar::reset() { _shfit = 3; }