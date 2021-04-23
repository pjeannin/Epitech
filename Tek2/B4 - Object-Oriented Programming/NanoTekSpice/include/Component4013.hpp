/*
** EPITECH PROJECT, 2021
** tekspice
** File description:
** Component.hpp
*/

#ifndef __COMPONENT4013_HH__
#define __COMPONENT4013_HH__

#include "AComponent.hpp"

namespace nts
{
    class Component4013 : public AComponent
    {
        public:
            Component4013(std::string const &name);
            ~Component4013();

            virtual nts::Tristate compute(std::size_t pin);

        private:

    };
}

#endif