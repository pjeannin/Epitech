/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** Cure
*/

#ifndef CURE_HPP_
#define CURE_HPP_

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria{
    public:
        Cure();
        ~Cure();
        AMateria *clone() const;
        void use(ICharacter &target);

    protected:
    private:
};

#endif /* !CURE_HPP_ */
