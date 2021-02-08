/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-pierre.jeannin
** File description:
** Carrier
*/

#ifndef CARRIER_HPP_
#define CARRIER_HPP_

#include <string>
#include <stdlib.h>
#include "Droid.hpp"

class Carrier {
    public:
        Carrier(std::string id = "");
        ~Carrier();
        void setId(std::string id);
        void setEnergy(size_t energy);
        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        size_t getSpeed() const;
        Carrier &operator<<(Droid *&droid);
        Carrier &operator>>(Droid *&droid);
        Droid *&operator[](int index) const;
        Carrier &operator~();
        bool operator()(int x, int y);
        Carrier &operator<<(size_t &energy);

    protected:
    private:
        int numberOfDroids() const;
        std::string _id;
        size_t _energy;
        const size_t _attack;
        const size_t _toughness;
        Droid **_droids;
};

std::ostream &operator<<(std::ostream &stream, const Carrier &carrier);

#endif /* !CARRIER_HPP_ */
