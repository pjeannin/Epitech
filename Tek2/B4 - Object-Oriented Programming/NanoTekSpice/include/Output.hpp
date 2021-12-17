/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "AComponent.hpp"

namespace nts {
    class Output : public AComponent {
        public:
            Output(std::string const &name);
            ~Output();

            virtual void          simulate(std::size_t tick);
            virtual nts::Tristate compute(std::size_t pin);

        protected:
        private:
    };
}

#endif /* !OUTPUT_HPP_ */
