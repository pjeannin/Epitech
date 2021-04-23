/*
** EPITECH PROJECT, 2021
** bootstrap_nanoTekSpice
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include <vector>
#include "IComponent.hpp"

namespace nts {
    class Pin {
        public:
        enum Mode {
            INPUT,
            OUTPUT,
            VSS,
            VDD
        };
            Pin(Mode mode, Tristate state);
            ~Pin();
            Mode getMode() const;
            Tristate getState() const;
            std::vector<IComponent *> getTargetComponent();
            std::vector<int> getTargetPin() const;
            void setState(Tristate state);
            void setTargetComponenet(IComponent *component);
            void setTargetPin(int pin);

        protected:
        private:
            Mode _mode;
            Tristate _state;
            std::vector<IComponent *>_targetComponent;
            std::vector<int> _targetPin;
    };
}

#endif /* !PIN_HPP_ */
