/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "AComponent.hpp"

namespace nts {
    class Input : public AComponent {
        public:
            Input(std::string const &name);
            ~Input();

            virtual void          simulate(std::size_t tick);
            virtual nts::Tristate compute(std::size_t pin);
        protected:
        private:
    };
}

#endif /* !INPUT_HPP_ */