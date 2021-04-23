/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** False
*/

#include "../../include/False.hpp"

namespace nts {
    False::False(std::string const &name) : AComponent(name)
    {
        _pins.push_back(*new Pin(Pin::OUTPUT, FALSE));
    }

    False::~False()
    {
    }

    nts::Tristate False::compute(std::size_t pin)
    {
        if (pin != 0)
            throw Error("Compute ComponentFalse", "Can't compute another pin than an output");

        return (_pins[0].getState());
    }

    void False::simulate(std::size_t tick) { }
}