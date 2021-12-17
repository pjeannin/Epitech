/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD17-pierre.jeannin
** File description:
** Encryption
*/

#include "Encryption.hpp"

Encryption::Encryption(IEncryptionMethod &iencryptioninstance, Methode iencryptionmethode) : _iencryptioninstance(&iencryptioninstance), _iencryptionmethode(iencryptionmethode)
{
}

Encryption::~Encryption()
{
}

void Encryption::operator()(char c) { (_iencryptioninstance->*_iencryptionmethode)(c); }

void Encryption::encryptString(IEncryptionMethod &encryptionMethod, const std::string &toEncrypt)
{
    encryptionMethod.reset();
    std::for_each(toEncrypt.begin(), toEncrypt.end(), Encryption(encryptionMethod, &IEncryptionMethod::encryptChar));
    std::cout << std::endl;
}

void Encryption::decryptString(IEncryptionMethod &encryptionMethod, const std::string &toDecrypt)
{
    encryptionMethod.reset();
    std::for_each(toDecrypt.begin(), toDecrypt.end(), Encryption(encryptionMethod, &IEncryptionMethod::decryptChar));
    std::cout << std::endl;
}