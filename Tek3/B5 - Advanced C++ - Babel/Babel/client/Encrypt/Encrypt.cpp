/*
** EPITECH PROJECT, 2021
** EncryptedString
** File description:
** Project File
*/

#include "Encrypt.hpp"

const std::string Babel::Client::Encryption::encrypt(const std::string& password, const std::string &key)
{
    std::string tmp = generate_key(key);
    std::string newPassword = *new std::string(password);
    std::string newKey = *new std::string(key);

    while (newKey.size() < newPassword.size())
        newKey += tmp;
    for (std::string::size_type i = 0; i < newPassword.size(); ++i)
        newPassword[i] ^= newKey[i];
    return (newPassword);
}

const std::string Babel::Client::Encryption::decrypt(const std::string& encrypted_password, const std::string &key)
{
    return (encrypt(encrypted_password, generate_key(key)));
}

const std::string Babel::Client::Encryption::generate_key(const std::string& string)
{
    std::string key = string.substr(0, string.find('@'));
    for (char & i : key)
        i += 3;
    return (key);
}