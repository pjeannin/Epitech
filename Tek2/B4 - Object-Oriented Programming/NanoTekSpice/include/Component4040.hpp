/*
** EPITECH PROJECT, 2021
** tekspice
** File description:
** Component.hpp
*/

#ifndef __COMPONENT4040_HH__
#define __COMPONENT4040_HH__

#include "AComponent.hpp"

namespace nts
{
    class Component4040 : public AComponent
    {
        public:
            Component4040(std::string const &name);
            ~Component4040();

            virtual nts::Tristate compute(std::size_t pin);

        private:

    };
}

#endif