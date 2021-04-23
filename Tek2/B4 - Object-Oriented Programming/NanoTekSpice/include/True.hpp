/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "AComponent.hpp"

namespace nts {
    class True : public AComponent {
        public:
            True(std::string const &name);
            ~True();

            virtual void          simulate(std::size_t tick);
            virtual nts::Tristate compute(std::size_t pin);

        protected:
        private:
    };
}

#endif /* !TRUE_HPP_ */
