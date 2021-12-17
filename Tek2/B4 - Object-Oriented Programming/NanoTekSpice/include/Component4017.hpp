/*
** EPITECH PROJECT, 2021
** tekspice
** File description:
** Component.hpp
*/

#ifndef __COMPONENT4017_HH__
#define __COMPONENT4017_HH__

#include "AComponent.hpp"

namespace nts
{
    class Component4017 : public AComponent
    {
        public:
            Component4017(std::string const &name);
            ~Component4017();

            virtual nts::Tristate compute(std::size_t pin);

        private:

    };
}

#endif