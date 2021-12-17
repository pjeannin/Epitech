/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** Utils.cpp
*/

#include "Utils.hpp"

std::vector<std::string> &splitArgs(std::string args, char delim)
{
    std::vector<std::string> *splittedArgs = new std::vector<std::string>;
    size_t pos = 0;
    std::string token;
    while ((pos = args.find(delim)) != std::string::npos) {
        token = args.substr(0, pos);
        splittedArgs->push_back(token);
        args.erase(0, pos + 1);
    }
    splittedArgs->push_back(token);
    return *splittedArgs;
}