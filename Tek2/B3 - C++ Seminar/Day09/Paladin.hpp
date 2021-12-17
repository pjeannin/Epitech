/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD09-pierre.jeannin
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin : virtual public Warrior, virtual public Priest {
    public:
        Paladin(const std::string &name, int level);
        Paladin(const std::string &name, int level, std::string weapon);
        ~Paladin();
        int CloseAttack();
        void Heal();
        int RangeAttack();
        int Intercept();
        void RestorePower();

    protected:
    private:
        static const int _pvDefault = 100;
        static const int _powerDefault = 100;
        static const int _strengthDefault = 9;
        static const int _staminaDefault = 10;
        static const int _intelligenceDefault = 10;
        static const int _spiritDefault = 10;
        static const int _agilityDefault = 2;
};

#endif /* !PALADIN_HPP_ */
