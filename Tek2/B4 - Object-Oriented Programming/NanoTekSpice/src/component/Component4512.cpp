/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Component4512
*/

#include "../../include/Component4512.hpp"

namespace nts {
    Component4512::Component4512(std::string const &name) : AComponent(name)
    {
    }

    Component4512::~Component4512()
    {
    }

    nts::Tristate Component4512::compute(std::size_t pin) { return (UNDEFINED); }
}