/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** AComponent
*/

#include "../../include/AComponent.hpp"

namespace nts {
    AComponent::AComponent(std::string const &name) : _name(name), _newPinValue(UNDEFINED)
    {
    }

    AComponent::~AComponent()
    {
    }

    void AComponent::dump() const {
        std::cout << _name << ":" << std::endl;
        for (int i = 0; i < _pins.size(); ++i) {
            std::string state;
            switch (_pins[i].getState())
            {
            case nts::Tristate::TRUE:
                state = "1";
                break;
            case nts::Tristate::FALSE:
                state = "0";
                break;
            default:
                state = "U";
                break;
            }
            std::cout << "Pin " << i + 1 << ": " << state << std::endl;
        }
    }

    const std::string &AComponent::getName() const { return (_name); }

    std::vector<Pin> &AComponent::getPins() { return (_pins); }

    void AComponent::setName(const std::string &name) { _name = name; }

    void AComponent::setLink(std::size_t pin, nts::IComponent &other, std:: size_t otherPin)
    {
        AComponent *otherAComponent = dynamic_cast<AComponent *>(&other);

        if (pin - 1 >= _pins.size() || otherPin - 1 >= otherAComponent->_pins.size())
            throw Error("SetLink", "Wrong pin number");
        nts::Pin::Mode mode = _pins[pin - 1].getMode();
        nts::Pin::Mode targetMode = otherAComponent->getPins()[otherPin - 1].getMode();
        if (mode == nts::Pin::Mode::VDD || mode == nts::Pin::Mode::VSS
        || targetMode == nts::Pin::Mode::VDD || targetMode == nts::Pin::Mode::VSS
        || mode == targetMode)
            throw Error("SetLink", "Wrong pin mode chipset " + _name);
        _pins[pin - 1].setTargetComponenet(&other);
        _pins[pin - 1].setTargetPin(otherPin - 1);
    }

    void AComponent::setPinValue(int pin, nts::Tristate state)
    {
        _pins[pin].setState(state);
    }

    void AComponent::setNewPinValue(nts::Tristate state) { _newPinValue = state; }

    void AComponent::simulate(std::size_t tick)
    {
        for (int i = 0; i < _pins.size(); ++i) {
            if (_pins[i].getMode() == nts::Pin::INPUT)
                _pins[i].getTargetComponent()[0]->simulate(tick);
        }
    }

    nts::Tristate AComponent::compute(std::size_t pin) { return (UNDEFINED); }
}