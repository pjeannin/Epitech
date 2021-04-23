/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Component2716
*/

#include "../../include/Component2716.hpp"

namespace nts {
    Component2716::Component2716(std::string const &name) : AComponent(name)
    {
    }

    Component2716::~Component2716()
    {
    }

    nts::Tristate Component2716::compute(std::size_t pin) { return (UNDEFINED); }
}