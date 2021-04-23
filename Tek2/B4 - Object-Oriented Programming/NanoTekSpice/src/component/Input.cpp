/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Input
*/

#include "../../include/Input.hpp"

namespace nts {
    Input::Input(std::string const &name) : AComponent(name)
    {
        _pins.push_back(*new Pin(Pin::OUTPUT, UNDEFINED));
    }

    Input::~Input()
    {
    }

    nts::Tristate Input::compute(std::size_t pin)
    {
        if (pin != 0)
            throw Error("Compute ComponentInput", "Can't compute another pin than an output");

        return (_pins[0].getState());
    }

    void Input::simulate(std::size_t tick) { setPinValue(0, _newPinValue); }
}