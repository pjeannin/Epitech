/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD09-pierre.jeannin
** File description:
** Warrior
*/

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include "Character.hpp"

class Warrior : virtual public Character {
    public:
        Warrior(const std::string &name, int level);
        Warrior(const std::string &name, int level, std::string weapon);
        ~Warrior();
        virtual int CloseAttack();
        virtual int RangeAttack();

    protected:
        Warrior();
        std::string _weapon;
    private:
        static const int _pvDefault = 100;
        static const int _powerDefault = 100;
        static const int _strengthDefault = 12;
        static const int _staminaDefault = 12;
        static const int _intelligenceDefault = 5;
        static const int _spiritDefault = 12;
        static const int _agilityDefault = 12;
};

#endif /* !WARRIOR_HPP_ */
