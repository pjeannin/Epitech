/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Circuit
*/

#include "../../include/Circuit.hpp"

namespace nts {
    Circuit::Circuit()
    {
    }

    void Circuit::simulate(std::size_t tick) { }

    nts::Tristate Circuit::compute(std::size_t pin) { return (UNDEFINED); }

    void Circuit::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) { }

    void Circuit::dump() const
    {
        for (int i = 0; i < _allComponent.size(); ++i) {
            _allComponent[i]->dump();
            if (i != _allComponent.size() - 1)
                std::cout << std::endl;
        }
    }

    void Circuit::addComponent(IComponent *component) { _allComponent.push_back(component); }

    void Circuit::addInput(IComponent *component) { _inputs.push_back(component); }

    void Circuit::addOutput(IComponent *component) { _outputs.push_back(component); }

    std::vector<IComponent *> &Circuit::getAllComponent() { return (_allComponent); }

    std::vector<IComponent *> &Circuit::getInputs() { return (_inputs); }

    std::vector<IComponent *> &Circuit::getOutputs() { return (_outputs); }

    IComponent *Circuit::getComponent(const std::string &name)
    {
        for (int i = 0; i < _allComponent.size(); ++i) {
            AComponent *tmp = dynamic_cast<AComponent *>(_allComponent[i]);
            if (tmp->getName() == name)
                return (tmp);
        }

        return (nullptr);
    }
}