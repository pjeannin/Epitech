/*
** EPITECH PROJECT, 2021
** EncryptedString
** File description:
** Project File
*/

#include "iostream"

#ifndef ENCRYPTEDSTRING_ENCRYPT_HPP
#define ENCRYPTEDSTRING_ENCRYPT_HPP

namespace Babel::Client {
    class Encryption{
        public :
            static const std::string encrypt(const std::string& password, const std::string &key);
            static const std::string decrypt(const std::string& encrypted_password, const std::string &key);
        private:
            static const std::string generate_key(std::string const& string);
    };
}

#endif //ENCRYPTEDSTRING_ENCRYPT_HPP
