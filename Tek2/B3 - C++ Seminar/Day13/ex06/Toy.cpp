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

bool Toy::setAscii(const std::string &fileName)
{
    if (!_picture.getPictureFromFile(fileName)) {
        _error.setType(Error::PICTURE);
        return (false);
    }
    return (true);
}

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
    if (_type == BUZZ)
        std::cout << "BUZZ: ";
    else if (_type == WOODY)
        std::cout << "WOODY: ";
    std::cout << _name << " \"" << talk << "\"" << std::endl;

    return (true);
}


bool Toy::speak_es(const std::string talk)
{
    if (_type == BUZZ) {
        std::cout << "BUZZ: " << _name << " senorita \"" << talk << "\" senorita" << std::endl;
        return (true);
    }
    _error.setType(Error::SPEAK);

    return (false);
}

std::ostream& operator<<(std::ostream &stream, Toy const &toy)
{
    return (stream << toy.getName() << std::endl << toy.getAscii() << std::endl);
}

Toy::Error Toy::getLastError() { return (_error); }

Toy::Error::Error() : type(UNKNOWN)
{
}

Toy::Error::~Error()
{
}

void Toy::Error::setType(ErrorType newType) { type = newType; }

const std::string &Toy::Error::what() const
{
    switch (type)
    {
    case UNKNOWN:
        return (*new std::string(""));
        break;
    case PICTURE:
        return (*new std::string("bad new illustration"));
        break;
    case SPEAK:
        return (*new std::string("wrong mode"));
        break;
    default:
        break;
    }
}

const std::string &Toy::Error::where() const
{
    switch (type)
    {
    case UNKNOWN:
        return (*new std::string(""));
        break;
    case PICTURE:
        return (*new std::string("setAscii"));
        break;
    case SPEAK:
        return (*new std::string("speak_es"));
        break;
    default:
        break;
    }
}