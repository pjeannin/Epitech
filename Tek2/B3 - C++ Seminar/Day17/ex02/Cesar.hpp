/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD17-pierre.jeannin
** File description:
** Cesar
*/

#ifndef CESAR_HPP_
#define CESAR_HPP_

#include <ctype.h>
#include <iostream>
#include "IEncryptionMethod.hpp"

class Cesar : public IEncryptionMethod {
    public:
        Cesar();
        ~Cesar();
        void encryptChar(char plainchar);
        void decryptChar(char cipherchar);
        void reset();

    protected:
    private:
        int _shfit;
};

#endif /* !CESAR_HPP_ */
