/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-pierre.jeannin
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(const ToyType type, const std::string &name, const std::string &pictureFileName) : _name(name), _type(type), _picture(*new Picture(pictureFileName))
{
}

Toy::Toy() : _name("toy"), _type(BASIC_TOY), _picture(*new Picture())
{
}


Toy::~Toy()
{
}


const Toy::ToyType &Toy::getType() const { return (_type); }

const std::string &Toy::getName() const { return (_name); }

const std::string &Toy::getAscii() const { return (_picture.data); }

void Toy::setName(const std::string &name) { _name = name; }

bool Toy::setAscii(const std::string &fileName) { return (_picture.getPictureFromFile(fileName)); }