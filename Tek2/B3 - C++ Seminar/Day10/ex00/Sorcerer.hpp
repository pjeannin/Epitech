/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** Sorcerer
*/

#ifndef SORCERER_HPP_
#define SORCERER_HPP_

#include <string>
#include <iostream>
#include "Victim.hpp"

class Sorcerer {
    public:
        Sorcerer(std::string name, std::string title);
        ~Sorcerer();
        std::string  const &getName() const;
        std::string  const &getTitle() const;
        void polymorph(const Victim &victim) const;

    protected:
    private:
        std::string _name;
        std::string _title;
};

std::ostream &operator<<(std::ostream &stream, const Sorcerer& sorcerer);

#endif /* !SORCERER_HPP_ */
