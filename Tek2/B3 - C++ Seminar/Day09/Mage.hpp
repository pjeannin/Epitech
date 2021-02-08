/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD09-pierre.jeannin
** File description:
** Mage
*/

#ifndef MAGE_HPP_
#define MAGE_HPP_

#include "Character.hpp"

class Mage : virtual public Character {
    public:
        Mage(const std::string &name, int level);
        ~Mage();
        virtual int CloseAttack();
        virtual int RangeAttack();
        virtual void RestorePower();

    protected:
        Mage();
    private:
        static const int _pvDefault = 100;
        static const int _powerDefault = 100;
        static const int _strengthDefault = 6;
        static const int _staminaDefault = 6;
        static const int _intelligenceDefault = 12;
        static const int _spiritDefault = 11;
        static const int _agilityDefault = 7;
};

#endif /* !MAGE_HPP_ */
