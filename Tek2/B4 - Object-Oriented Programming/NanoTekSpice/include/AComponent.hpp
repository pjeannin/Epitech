/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include <vector>
#include <string>
#include "IComponent.hpp"
#include "Pin.hpp"
#include "Gates.hpp"
#include "Error.hpp"

namespace nts {
    class AComponent : public IComponent {
        public:
            AComponent(std::string const &name);
            ~AComponent();

            virtual void simulate(std::size_t tick);
            virtual nts::Tristate compute(std::size_t pin);
            virtual void setLink(std::size_t pin, nts::IComponent &other, std:: size_t otherPin);
            virtual void dump() const;

            const std::string &getName() const;
            std::vector<Pin> &getPins();
            void setName(const std::string &name);
            void setPinValue(int pin, nts::Tristate state);
            void setNewPinValue(nts::Tristate state);
        protected:
            std::string _name;
            std::vector<Pin> _pins;
            nts::Tristate _newPinValue;
        private:
    };
}

#endif /* !ACOMPONENT_HPP_ */
