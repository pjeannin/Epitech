/*
** EPITECH PROJECT, 2021
** tekspice
** File description:
** Component.hpp
*/

#ifndef __COMPONENT4008_HH__
#define __COMPONENT4008_HH__

#include "AComponent.hpp"

namespace nts
{
    class Component4008 : public AComponent
    {
        public:
            Component4008(std::string const &name);
            ~Component4008();

            virtual nts::Tristate compute(std::size_t pin);

        private:

    };
}

#endif