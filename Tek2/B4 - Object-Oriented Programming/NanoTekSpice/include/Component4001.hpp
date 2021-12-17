/*
** EPITECH PROJECT, 2021
** tekspice
** File description:
** Component.hpp
*/

#ifndef __COMPONENT4001_HH__
#define __COMPONENT4001_HH__

#include "AComponent.hpp"

namespace nts
{
    class Component4001 : public AComponent
    {
        public:
            Component4001(std::string const &name);
            ~Component4001();

            virtual nts::Tristate compute(std::size_t pin);

        private:

    };
}

#endif