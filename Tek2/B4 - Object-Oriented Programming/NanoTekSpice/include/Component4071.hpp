/*
** EPITECH PROJECT, 2021
** tekspice
** File description:
** Component.hpp
*/

#ifndef __COMPONENT4071_HH__
#define __COMPONENT4071_HH__

#include "AComponent.hpp"

namespace nts
{
    class Component4071 : public AComponent
    {
        public:
            Component4071(std::string const &name);
            ~Component4071();

            virtual nts::Tristate compute(std::size_t pin);

        private:

    };
}

#endif