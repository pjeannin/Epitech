/*
** EPITECH PROJECT, 2021
** tekspice
** File description:
** Component.hpp
*/

#ifndef __COMPONENT4069_HH__
#define __COMPONENT4069_HH__

#include "AComponent.hpp"

namespace nts
{
    class Component4069 : public AComponent
    {
        public:
            Component4069(std::string const &name);
            ~Component4069();

            virtual nts::Tristate compute(std::size_t pin);

        private:

    };
}

#endif