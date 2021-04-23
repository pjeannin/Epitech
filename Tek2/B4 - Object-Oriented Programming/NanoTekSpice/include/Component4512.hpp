/*
** EPITECH PROJECT, 2021
** tekspice
** File description:
** Component.hpp
*/

#ifndef __COMPONENT4512_HH__
#define __COMPONENT4512_HH__

#include "AComponent.hpp"

namespace nts
{
    class Component4512 : public AComponent
    {
        public:
            Component4512(std::string const &name);
            ~Component4512();

            virtual nts::Tristate compute(std::size_t pin);

        private:

    };
}

#endif