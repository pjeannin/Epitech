/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-pierre.jeannin
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture() : data("")
{
}

Picture::Picture(const std::string &file)
{
    if (!getPictureFromFile(file))
        data = "ERROR";
}

Picture::~Picture()
{
}


bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream fileStream(file, std::ios::in);
    char c;

    if (!fileStream.is_open())
        return (false);
    data = *new std::string("");
    while (fileStream.get(c))
        data += c;

    return (true);
}