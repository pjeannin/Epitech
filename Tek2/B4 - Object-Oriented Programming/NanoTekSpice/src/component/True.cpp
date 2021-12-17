/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** True
*/

#include "../../include/True.hpp"

namespace nts {
    True::True(std::string const &name) : AComponent(name)
    {
        _pins.push_back(*new Pin(Pin::OUTPUT, TRUE));
    }

    True::~True()
    {
    }

    nts::Tristate True::compute(std::size_t pin)
    {
        if (pin != 0)
            throw Error("Compute ComponentTrue", "Can't compute another pin than an output");

        return (_pins[0].getState());
    }

    void True::simulate(std::size_t tick) { }
}