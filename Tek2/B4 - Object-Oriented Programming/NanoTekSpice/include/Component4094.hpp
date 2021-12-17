/*
** EPITECH PROJECT, 2021
** tekspice
** File description:
** Component.hpp
*/

#ifndef __COMPONENT4094_HH__
#define __COMPONENT4094_HH__

#include "AComponent.hpp"

namespace nts
{
    class Component4094 : public AComponent
    {
        public:
            Component4094(std::string const &name);
            ~Component4094();

            virtual nts::Tristate compute(std::size_t pin);

        private:

    };
}

#endif