/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Output
*/

#include "../../include/Output.hpp"

namespace nts {
    Output::Output(std::string const &name) : AComponent(name)
    {
        _pins.push_back(*new Pin(Pin::INPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::OUTPUT, UNDEFINED));
    }

    Output::~Output()
    {
    }

    nts::Tristate Output::compute(std::size_t pin)
    {
        if (pin != 0)
            throw Error("Compute ComponentOutput", "Can't compute another pin than an output");

        return (_pins[0].getState());
    }

    void Output::simulate(std::size_t tick)
    {
        _pins[0].getTargetComponent()[0]->simulate(tick);
        _pins[0].setState(_pins[0].getTargetComponent()[0]->compute(_pins[0].getTargetPin()[0]));
    }
}