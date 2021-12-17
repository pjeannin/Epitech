/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-pierre.jeannin
** File description:
** Gates
*/

#ifndef GATES_HPP_
#define GATES_HPP_

#include "IComponent.hpp"

namespace nts {
    class Gates {
        public:
            static Tristate norGate(Tristate a, Tristate b);
            static Tristate nandGate(Tristate a, Tristate b);
            static Tristate xorGate(Tristate a, Tristate b);
            static Tristate orGate(Tristate a, Tristate b);
            static Tristate andGate(Tristate a, Tristate b);
            static Tristate inverterGate(Tristate a);
        protected:
        private:
    };
}

#endif /* !GATES_HPP_ */
