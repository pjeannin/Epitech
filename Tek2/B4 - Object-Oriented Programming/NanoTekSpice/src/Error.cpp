/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Error
*/

#include "../include/Error.hpp"

Error::Error(const std::string &where, const std::string &what) throw() : _where(where), _what(what)
{
}

Error::~Error() throw()
{
}

const std::string &Error::where() throw()  { return (_where); }

const char *Error::what() throw() { return (_what.c_str()); }