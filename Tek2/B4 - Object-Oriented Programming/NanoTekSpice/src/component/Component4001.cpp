/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Component4001
*/

#include "../../include/Component4001.hpp"

namespace nts {
    Component4001::Component4001(std::string const &name) : AComponent(name)
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

    Component4001::~Component4001()
    {
    }

    nts::Tristate Component4001::compute(std::size_t pin)
    {
        switch (pin)
        {
        case 2:
            _pins[0].setState(_pins[0].getTargetComponent()[0]->compute(_pins[0].getTargetPin()[0]));
            _pins[1].setState(_pins[1].getTargetComponent()[0]->compute(_pins[1].getTargetPin()[0]));
            _pins[2].setState(Gates::norGate(_pins[0].getState(), _pins[1].getState()));
            return (_pins[2].getState());
            break;
        case 3:
            _pins[4].setState(_pins[4].getTargetComponent()[0]->compute(_pins[4].getTargetPin()[0]));
            _pins[5].setState(_pins[5].getTargetComponent()[0]->compute(_pins[5].getTargetPin()[0]));
            _pins[3].setState(Gates::norGate(_pins[4].getState(), _pins[5].getState()));
            return (_pins[3].getState());
            break;
        case 9:
            _pins[7].setState(_pins[7].getTargetComponent()[0]->compute(_pins[7].getTargetPin()[0]));
            _pins[9].setState(_pins[8].getTargetComponent()[0]->compute(_pins[8].getTargetPin()[0]));
            _pins[9].setState(Gates::norGate(_pins[7].getState(), _pins[8].getState()));
            return (_pins[9].getState());
            break;
        case 10:
            _pins[11].setState(_pins[11].getTargetComponent()[0]->compute(_pins[11].getTargetPin()[0]));
            _pins[12].setState(_pins[12].getTargetComponent()[0]->compute(_pins[12].getTargetPin()[0]));
            _pins[10].setState(Gates::norGate(_pins[11].getState(), _pins[12].getState()));
            return (_pins[10].getState());
            break;
        default:
            throw Error("Compute Component4081", "Can't compute another pin than an output");
            break;
        }
    }
}