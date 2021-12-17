/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <vector>
#include "Create.hpp"
#include "IComponent.hpp"

namespace nts {
    class Circuit : public IComponent {
        public:
            Circuit();

            void          simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void          setLink(std::size_t pin, nts::IComponent &other, std:: size_t otherPin);
            void          dump() const;
            void addComponent(IComponent *component);
            void addInput(IComponent *component);
            void addOutput(IComponent *component);
            std::vector<IComponent *> &getAllComponent();
            std::vector<IComponent *> &getInputs();
            std::vector<IComponent *> &getOutputs();
            IComponent *getComponent(const std::string &name);

        protected:
        private:
            std::vector<IComponent *> _inputs;
            std::vector<IComponent *> _outputs;
            std::vector<IComponent *> _allComponent;
    };
}

#endif /* !CIRCUIT_HPP_ */