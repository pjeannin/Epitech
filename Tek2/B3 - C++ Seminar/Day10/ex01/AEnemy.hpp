/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** AEnemy
*/

#ifndef AENEMY_HPP_
#define AENEMY_HPP_

#include <iostream>
#include <string>

class AEnemy {
    public:
        AEnemy(int hp, const std::string &type);
        virtual ~AEnemy();
        void takeDamage(int damage);
        std::string const &getType() const;
        int getHP() const;

    protected:
        const std::string _type;
        int _hp;
    private:
};

#endif /* !AENEMY_HPP_ */
