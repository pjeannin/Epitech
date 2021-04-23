/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Component4017
*/

#include "../../include/Component4017.hpp"

namespace nts {
    Component4017::Component4017(std::string const &name) : AComponent(name)
    {
        _pins.push_back(*new Pin(Pin::INPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::INPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::OUTPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::OUTPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::INPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::INPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::VSS, UNDEFINED));
        _pins.push_back(*new Pin(Pin::INPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::INPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::OUTPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::OUTPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::INPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::INPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::VDD, UNDEFINED));
    }

    Component4017::~Component4017()
    {
    }

    nts::Tristate Component4017::compute(std::size_t pin) { return (UNDEFINED); }
}