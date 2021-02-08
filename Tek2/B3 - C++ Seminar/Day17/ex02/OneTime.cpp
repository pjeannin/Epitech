/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD17-pierre.jeannin
** File description:
** OneTime
*/

#include "OneTime.hpp"

OneTime::OneTime(const std::string &key) : _key(key), _shift(0)
{
}

OneTime::~OneTime()
{
}

void OneTime::encryptChar(char plainchar)
{
    if (isalpha(plainchar))
        plainchar = (plainchar - (plainchar > 96 ? 97 : 65) + (_key[_shift] - (_key[_shift] > 96 ? 97 : 65))) % 26 + (plainchar > 96 ? 97 : 65);
    _shift = (_shift + 1) % _key.size();
    std::cout << plainchar;
}

void OneTime::decryptChar(char cipherchar)
{
    if (isalpha(cipherchar))
        cipherchar = ((cipherchar - (cipherchar > 96 ? 97 : 65) - (_key[_shift] - (_key[_shift] > 96 ? 97 : 65))) % 26 + ((cipherchar - (cipherchar > 96 ? 97 : 65) - (_key[_shift] - (_key[_shift] > 96 ? 97 : 65))) % 26 < 0 ? 26 : 0)) + (cipherchar > 96 ? 97 : 65);
    _shift = (_shift + 1) % _key.size();
    std::cout << cipherchar;
}

void OneTime::reset() { _shift = 0; }