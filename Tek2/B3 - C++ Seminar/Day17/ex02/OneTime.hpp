/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD17-pierre.jeannin
** File description:
** OneTime
*/

#ifndef ONETIME_HPP_
#define ONETIME_HPP_

#include <ctype.h>
#include <string>
#include <iostream>
#include "IEncryptionMethod.hpp"

class OneTime : public IEncryptionMethod {
    public:
        OneTime(const std::string &key);
        ~OneTime();
        void encryptChar(char plainchar);
        void decryptChar(char cipherchar);
        void reset();

    protected:
    private:
        std::string _key;
        unsigned int _shift;
};

#endif /* !ONETIME_HPP_ */
