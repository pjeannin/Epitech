/*
** EPITECH PROJECT, 2021
** tekspice
** File description:
** Component.hpp
*/

#ifndef __COMPONENT4081_HH__
#define __COMPONENT4081_HH__

#include "AComponent.hpp"

namespace nts
{
    class Component4081 : public AComponent
    {
        public:
            Component4081(std::string const &name);
            ~Component4081();

            virtual nts::Tristate compute(std::size_t pin);

        private:

    };
}

#endif