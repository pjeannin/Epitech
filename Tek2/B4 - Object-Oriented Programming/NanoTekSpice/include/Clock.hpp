/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "AComponent.hpp"

namespace nts {
    class Clock : public AComponent {
        public:
            Clock(std::string const &name);
            ~Clock();

            virtual void          simulate(std::size_t tick);
            virtual nts::Tristate compute(std::size_t pin);

        protected:
        private:
            std::size_t _lastTick;
    };
}

#endif /* !CLOCK_HPP_ */
