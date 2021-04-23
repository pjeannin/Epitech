/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Clock
*/

#include "../../include/Clock.hpp"

namespace nts {
Clock::Clock(std::string const &name) : AComponent(name), _lastTick(1)
    {
        _pins.push_back(*new Pin(Pin::OUTPUT, UNDEFINED));
    }

    Clock::~Clock()
    {
    }

    nts::Tristate Clock::compute(std::size_t pin)
    {
        if (pin != 0)
            throw Error("Compute ComponentClock", "Can't compute another pin than an output");

        return (_pins[0].getState());
    }

    void Clock::simulate(std::size_t tick)
    {
        if (tick == _lastTick)
            return;
        if (_newPinValue != UNDEFINED) {
            setPinValue(0, _newPinValue);
            _newPinValue = UNDEFINED;
        }
        _lastTick = tick;
        switch (_pins[0].getState())
        {
        case nts::TRUE:
            _pins[0].setState(FALSE);
            break;
        case nts::FALSE:
            _pins[0].setState(TRUE);
            break;
        default:
            break;
        }
    }
}