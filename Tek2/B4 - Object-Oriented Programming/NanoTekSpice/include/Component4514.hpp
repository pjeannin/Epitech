/*
** EPITECH PROJECT, 2021
** tekspice
** File description:
** Component.hpp
*/

#ifndef __COMPONENT4514_HH__
#define __COMPONENT4514_HH__

#include "AComponent.hpp"

namespace nts
{
    class Component4514 : public AComponent
    {
        public:
            Component4514(std::string const &name);
            ~Component4514();

            virtual nts::Tristate compute(std::size_t pin);

        private:

    };
}

#endif