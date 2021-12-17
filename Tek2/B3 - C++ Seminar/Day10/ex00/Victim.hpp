/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** Victim
*/

#ifndef VICTIM_HPP_
#define VICTIM_HPP_

#include <iostream>
#include <string>

class Victim {
    public:
        Victim(std::string name);
        virtual ~Victim();
        virtual std::string  const &getName() const;
        virtual void getPolymorphed()const;

    protected:
        std::string _name;
    private:
};

std::ostream &operator<<(std::ostream &stream, const Victim& victim);

#endif /* !VICTIM_HPP_ */
