/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Component4013
*/

#include "../../include/Component4013.hpp"

namespace nts {
    Component4013::Component4013(std::string const &name) : AComponent(name)
    {
    }

    Component4013::~Component4013()
    {
    }

    nts::Tristate Component4013::compute(std::size_t pin) { return (UNDEFINED); }
}