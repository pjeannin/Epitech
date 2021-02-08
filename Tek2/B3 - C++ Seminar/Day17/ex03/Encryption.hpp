/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD17-pierre.jeannin
** File description:
** Encryption
*/

#ifndef ENCRYPTION_HPP_
#define ENCRYPTION_HPP_

#include <string>
#include <algorithm>
#include <iostream>
#include "IEncryptionMethod.hpp"

typedef void (IEncryptionMethod::*Methode)(char);

class Encryption {
    public:
        Encryption(IEncryptionMethod &iencryptioninstance, Methode iencryptionmethode);
        ~Encryption();
        void operator()(char c);
        static void encryptString(IEncryptionMethod &encryptionMethod, const std::string &toEncrypt);
        static void decryptString(IEncryptionMethod &encryptionMethod, const std::string &toDecrypt);

    protected:
    private:
        IEncryptionMethod *_iencryptioninstance;
        Methode _iencryptionmethode;
};

#endif /* !ENCRYPTION_HPP_ */
