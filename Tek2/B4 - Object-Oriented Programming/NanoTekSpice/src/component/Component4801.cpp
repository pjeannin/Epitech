/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Component4801
*/

#include "../../include/Component4801.hpp"

namespace nts {
    Component4801::Component4801(std::string const &name) : AComponent(name)
    {
    }

    Component4801::~Component4801()
    {
    }

    nts::Tristate Component4801::compute(std::size_t pin) { return (UNDEFINED); }
}