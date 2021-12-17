/*
** EPITECH PROJECT, 2021
** tekspice
** File description:
** Component.hpp
*/

#ifndef __COMPONENT4030_HH__
#define __COMPONENT4030_HH__

#include "AComponent.hpp"

namespace nts
{
    class Component4030 : public AComponent
    {
        public:
            Component4030(std::string const &name);
            ~Component4030();

            virtual nts::Tristate compute(std::size_t pin);

        private:

    };
}

#endif