/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** PowerFist
*/

#ifndef POWERFIST_HPP_
#define POWERFIST_HPP_

#include "AWeapon.hpp"

class PowerFist : public AWeapon{
    public:
        PowerFist();
        ~PowerFist();
        virtual void attack() const;

    protected:
    private:
};

#endif /* !POWERFIST_HPP_ */
