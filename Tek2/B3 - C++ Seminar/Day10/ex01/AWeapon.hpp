/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** AWeapon
*/

#ifndef AWEAPON_HPP_
#define AWEAPON_HPP_

#include <iostream>
#include <string>

class AWeapon {
    public:
        AWeapon(const std::string &name, int apcost, int damage);
        virtual ~AWeapon();
        std::string const &getName() const;
        int getAPCost() const;
        int getDamage() const;
        virtual void attack() const = 0;

    protected:
        const std::string _name;
        int _damage;
        int _APcost;
    private:
};

#endif /* !AWEAPON_HPP_ */
