/*
** EPITECH PROJECT, 2021
** tekspice
** File description:
** Component.hpp
*/

#ifndef __COMPONENT2716_HH__
#define __COMPONENT2716_HH__

#include "AComponent.hpp"

namespace nts
{
    class Component2716 : public AComponent
    {
        public:
            Component2716(std::string const &name);
            ~Component2716();

            virtual nts::Tristate compute(std::size_t pin);

        private:

    };
}

#endif