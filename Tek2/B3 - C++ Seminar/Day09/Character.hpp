/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD09-pierre.jeannin
** File description:
**  Character
*/

#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include <string>
#include <iostream>

class Character {
    public:
        enum AttackRange { CLOSE, RANGE };

        Character(const std::string &name, int level);
        ~Character();
        const std::string &getName() const;
        int getLvl() const;
        int getPv() const;
        int getPower() const;
        int CloseAttack();
        int RangeAttack();
        void RestorePower();
        void Heal();
        void TakeDamage(int damage);

        AttackRange Range;
    protected:
        Character();
        std::string _name;
        int _level;
        int _pv;
        int _power;
        std::string _race;
        int _strength;
        int _stamina;
        int _intelligence;
        int _spirit;
        int _agility;

        static const int _pvDefault = 100;
        static const int _powerDefault = 100;
        static const int _strengthDefault = 5;
        static const int _staminaDefault = 5;
        static const int _intelligenceDefault = 5;
        static const int _spiritDefault = 5;
        static const int _agilityDefault = 5;
    private:
};

#endif /* !_CHARACTER_HPP_ */
