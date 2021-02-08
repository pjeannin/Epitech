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

Toy::Toy(const Toy &toy) : _name(*new std::string(toy._name)), _type(toy._type), _picture(*new Picture(toy._picture))
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

Toy &Toy::operator=(const Toy &toy)
{
    _name = *new std::string(toy._name);
    _type = toy._type;
    _picture = *new Picture(toy._picture);

    return (*this);
}

Toy &Toy::operator<<(const std::string &ascii)
{
    _picture.data = ascii;

    return (*this);
}

bool Toy::speak(const std::string talk)
{
    std::cout << _name << " \"" << talk << "\"" << std::endl;

    return (true);
}

std::ostream& operator<<(std::ostream &stream, Toy const &toy)
{
    return (stream << toy.getName() << std::endl << toy.getAscii() << std::endl);
}