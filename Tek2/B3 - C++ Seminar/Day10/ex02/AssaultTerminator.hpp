/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** AssaultTerminator
*/

#ifndef ASSAULTTERMINATOR_HPP_
#define ASSAULTTERMINATOR_HPP_

#include <iostream>
#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {
    public:
        AssaultTerminator();
        AssaultTerminator(const AssaultTerminator &AssaultTerminator);
        ~AssaultTerminator();
        ISpaceMarine *clone() const;
        void battleCry() const;
        void rangedAttack() const;
        void meleeAttack() const;

    protected:
    private:
};

#endif /* !ASSAULTTERMINATOR_HPP_ */
