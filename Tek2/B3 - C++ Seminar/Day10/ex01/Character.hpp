/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include "AEnemy.hpp"
#include "AWeapon.hpp"

class Character {
    public:
        Character(const std::string &name);
        ~Character();
        void recoverAP();
        void equip(AWeapon *weapon);
        void attack(AEnemy *enemy);
        std::string const &getName() const;
        int getAP() const;
        AWeapon *const &getCurrentWeapon() const;

    protected:
    private:
        const std::string _name;
        int _AP;
        AWeapon *_currentWeapon;
};

std::ostream &operator<<(std::ostream &stream, const Character &character);

#endif /* !CHARACTER_HPP_ */
