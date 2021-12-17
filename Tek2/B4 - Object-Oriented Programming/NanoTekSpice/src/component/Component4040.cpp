/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Component4040
*/

#include "../../include/Component4040.hpp"

namespace nts {
    Component4040::Component4040(std::string const &name) : AComponent(name)
    {
    }

    Component4040::~Component4040()
    {
    }

    nts::Tristate Component4040::compute(std::size_t pin) { return (UNDEFINED); }
}