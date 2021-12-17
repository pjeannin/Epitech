/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD08-pierre.jeannin
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <string>

class Droid {
    public:
        Droid(std::string serial = "");
        Droid(const Droid &referenceDroid);
        ~Droid();
        void setId(std::string id);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);
        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string *getStatus() const;
        bool operator==(Droid const &droid) const;
        bool operator!=(Droid const &droid) const;
        Droid &operator=(const Droid &referenceDroid);
        Droid &operator<<(size_t &energy);

    protected:
    private:
        std::string _id;
        size_t _energy;
        const size_t _attack;
        const size_t _toughness;
        std::string *_status;
};

std::ostream &operator<<(std::ostream &stream, const Droid & droid);

#endif /* !DROID_HPP_ */
