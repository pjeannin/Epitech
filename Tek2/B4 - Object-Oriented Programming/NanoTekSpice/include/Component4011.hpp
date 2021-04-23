/*
** EPITECH PROJECT, 2021
** tekspice
** File description:
** Component.hpp
*/

#ifndef __COMPONENT4011_HH__
#define __COMPONENT4011_HH__

#include "AComponent.hpp"

namespace nts
{
    class Component4011 : public AComponent
    {
        public:
            Component4011(std::string const &name);
            ~Component4011();

            virtual nts::Tristate compute(std::size_t pin);

        private:

    };
}

#endif