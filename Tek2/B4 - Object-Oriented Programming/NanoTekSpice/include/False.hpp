/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "AComponent.hpp"

namespace nts {
    class False : public AComponent {
        public:
            False(std::string const &name);
            ~False();

            virtual void          simulate(std::size_t tick);
            virtual nts::Tristate compute(std::size_t pin);

        protected:
        private:
    };
}

#endif /* !FALSE_HPP_ */
