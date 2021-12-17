/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Component4008
*/

#include "../../include/Component4008.hpp"

namespace nts {
    Component4008::Component4008(std::string const &name) : AComponent(name)
    {
    }

    Component4008::~Component4008()
    {
    }

    nts::Tristate Component4008::compute(std::size_t pin) { return (UNDEFINED); return (UNDEFINED);}
}