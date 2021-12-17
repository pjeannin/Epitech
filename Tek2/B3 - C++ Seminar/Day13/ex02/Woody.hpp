/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-pierre.jeannin
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy {
    public:
        Woody(const std::string &name, const std::string &FileName);
        Woody(const std::string &name);
        ~Woody();

    protected:
    private:
};

#endif /* !WOODY_HPP_ */
