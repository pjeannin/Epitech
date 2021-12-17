/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** Peon
*/

#ifndef PEON_HPP_
#define PEON_HPP_

#include "Victim.hpp"

class Peon : public Victim {
    public:
        Peon(std::string name);
        ~Peon();
        virtual void getPolymorphed() const;

    protected:
    private:
};

#endif /* !PEON_HPP_ */
