/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Pins
*/

#include "../include/Pin.hpp"

namespace nts {
    Pin::Pin(Mode mode, Tristate state) : _mode(mode), _state(state)
    {
    }

    Pin::~Pin()
    {
    }

    Pin::Mode Pin::getMode() const { return (_mode); }

    Tristate Pin::getState() const { return (_state); }

    std::vector<IComponent *> Pin::getTargetComponent() { return (_targetComponent); }

    std::vector<int> Pin::getTargetPin() const { return (_targetPin); }

    void Pin::setState(Tristate state) { _state = state; }

    void Pin::setTargetComponenet(IComponent *component) { _targetComponent.push_back(component); }

    void Pin::setTargetPin(int pin) { _targetPin.push_back(pin); }
}