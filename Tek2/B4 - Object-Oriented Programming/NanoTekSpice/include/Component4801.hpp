/*
** EPITECH PROJECT, 2021
** tekspice
** File description:
** Component.hpp
*/

#ifndef __COMPONENT4801_HH__
#define __COMPONENT4801_HH__

#include "AComponent.hpp"

namespace nts
{
    class Component4801 : public AComponent
    {
        public:
            Component4801(std::string const &name);
            ~Component4801();

            virtual nts::Tristate compute(std::size_t pin);

        private:

    };
}

#endif