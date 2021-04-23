/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Component4094
*/

#include "../../include/Component4094.hpp"

namespace nts {
    Component4094::Component4094(std::string const &name) : AComponent(name)
    {
    }

    Component4094::~Component4094()
    {
    }

    nts::Tristate Component4094::compute(std::size_t pin) { return (UNDEFINED); }
}