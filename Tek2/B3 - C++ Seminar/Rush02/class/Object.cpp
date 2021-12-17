/*
** EPITECH PROJECT, 2021
** rush2perso
** File description:
** Object
*/

#include "Object.hpp"

Object::Object(const std::string &title, const std::string &type)
{
    this->_title = title;
    this->_type = type;
}

Object::~Object()
{
}

const std::string &Object::getTitle() const
{
    return (this->_title);
}

const std::string &Object::getType() const
{
    return (this->_type);
}

std::ostream& operator<<(std::ostream &stream, Object const &object)
{
    return (stream << object.getTitle());
}