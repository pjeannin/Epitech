/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-pierre.jeannin
** File description:
** Supply
*/

#ifndef SUPPLY_HPP_
#define SUPPLY_HPP_

#include "Droid.hpp"

class Supply {
    public:
        enum Types { Iron = 1, Silicon = 2, Werk = 3 };
        Supply(Types type, size_t amout);
        Supply(Types type, size_t amout, Droid **werks);
        ~Supply();
        Types getType() const;
        Droid *&operator*() const;
        Supply *operator++();
        Supply *operator--();
        Supply *operator->();
        operator size_t() const { return (_amount); };
        void operator!();
        bool operator==(Types type) const;
        bool operator!=(Types type) const;

    protected:
    private:
        Types _type;
        size_t _amount;
        Droid **_werks;
        size_t _currentDroid;
};

std::ostream &operator<<(std::ostream &stream, const Supply &supply);

#endif /* !SUPPLY_HPP_ */
