/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD09-pierre.jeannin
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Mage.hpp"

class Priest : virtual public Mage {
    public:
        Priest(const std::string &name, int level);
        ~Priest();
        virtual int CloseAttack();
        virtual void Heal();

    protected:
        Priest();
    private:
        static const int _pvDefault = 100;
        static const int _powerDefault = 100;
        static const int _strengthDefault = 4;
        static const int _staminaDefault = 4;
        static const int _intelligenceDefault = 42;
        static const int _spiritDefault = 21;
        static const int _agilityDefault = 2;
};

#endif /* !PRIEST_HPP_ */
