/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Component4514
*/

#include "../../include/Component4514.hpp"

namespace nts {
    Component4514::Component4514(std::string const &name) : AComponent(name)
    {
    }

    Component4514::~Component4514()
    {
    }

    nts::Tristate Component4514::compute(std::size_t pin) { return (UNDEFINED); }
}