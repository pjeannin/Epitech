/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** TacticalMarine
*/

#ifndef TACTICALMARINE_HPP_
#define TACTICALMARINE_HPP_

#include <iostream>
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {
    public:
        TacticalMarine();
        TacticalMarine(const TacticalMarine &tacticalMarine);
        ~TacticalMarine();
        ISpaceMarine *clone() const;
        void battleCry() const;
        void rangedAttack() const;
        void meleeAttack() const;

    protected:
    private:
};

#endif /* !TACTICALMARINE_HPP_ */
