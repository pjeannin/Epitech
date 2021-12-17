/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-pierre.jeannin
** File description:
** Ratatouille
*/

#include "Ratatouille.hpp"

Ratatouille::Ratatouille()
{
    _ratatouille.str("");
}

Ratatouille::Ratatouille(const Ratatouille &other)
{
    _ratatouille.str("");
	_ratatouille << other._ratatouille.rdbuf();
}

Ratatouille::~Ratatouille()
{
}

Ratatouille &Ratatouille::operator=(const Ratatouille &other)
{
    _ratatouille.str("");
	_ratatouille << other._ratatouille.rdbuf();

    return (*this);
}

Ratatouille &Ratatouille::addVegetable(unsigned char c)
{
    _ratatouille << c;

    return (*this);
}

Ratatouille &Ratatouille::addCondiment(unsigned int i)
{
    _ratatouille << i;

    return (*this);
}

Ratatouille &Ratatouille::addSpice(double d)
{
    _ratatouille << d;

    return (*this);
}

Ratatouille &Ratatouille::addSauce(const std::string &s)
{
    _ratatouille << s.c_str();

    return (*this);
}

std::string Ratatouille::kooc()
{
    return (_ratatouille.str());
}