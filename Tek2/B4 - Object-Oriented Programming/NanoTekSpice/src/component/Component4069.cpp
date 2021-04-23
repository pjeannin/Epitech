/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Component4069
*/

#include "../../include/Component4069.hpp"

namespace nts {
    Component4069::Component4069(std::string const &name) : AComponent(name)
    {
        _pins.push_back(*new Pin(Pin::INPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::OUTPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::INPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::OUTPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::INPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::OUTPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::VSS, UNDEFINED));
        _pins.push_back(*new Pin(Pin::OUTPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::INPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::OUTPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::INPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::OUTPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::INPUT, UNDEFINED));
        _pins.push_back(*new Pin(Pin::VDD, UNDEFINED));
    }

    Component4069::~Component4069()
    {
    }

    nts::Tristate Component4069::compute(std::size_t pin)
    {
        switch (pin)
        {
        case 1:
            _pins[0].setState(_pins[0].getTargetComponent()[0]->compute(_pins[0].getTargetPin()[0]));
            _pins[1].setState(Gates::inverterGate(_pins[0].getState()));
            return (_pins[1].getState());
            break;
        case 3:
            _pins[2].setState(_pins[2].getTargetComponent()[0]->compute(_pins[2].getTargetPin()[0]));
            _pins[3].setState(Gates::inverterGate(_pins[2].getState()));
            return (_pins[3].getState());
            break;
        case 5:
            _pins[4].setState(_pins[4].getTargetComponent()[0]->compute(_pins[4].getTargetPin()[0]));
            _pins[5].setState(Gates::inverterGate(_pins[4].getState()));
            return (_pins[5].getState());
            break;
        case 7:
            _pins[8].setState(_pins[8].getTargetComponent()[0]->compute(_pins[8].getTargetPin()[0]));
            _pins[7].setState(Gates::inverterGate(_pins[8].getState()));
            return (_pins[7].getState());
            break;
        case 9:
            _pins[10].setState(_pins[10].getTargetComponent()[0]->compute(_pins[10].getTargetPin()[0]));
            _pins[9].setState(Gates::inverterGate(_pins[10].getState()));
            return (_pins[9].getState());
            break;
        case 11:
            _pins[12].setState(_pins[12].getTargetComponent()[0]->compute(_pins[12].getTargetPin()[0]));
            _pins[11].setState(Gates::inverterGate(_pins[12].getState()));
            return (_pins[11].getState());
            break;
        default:
            throw Error("Compute Component4069", "Can't compute another pin than an output");
            break;
        }
    }
}