/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** Ice
*/

#ifndef ICE_HPP_
#define ICE_HPP_

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria {
    public:
        Ice();
        ~Ice();
        AMateria *clone() const;
        void use(ICharacter &target);

    protected:
    private:
};

#endif /* !ICE_HPP_ */
