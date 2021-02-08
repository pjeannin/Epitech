/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-pierre.jeannin
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy {
    public:
        Buzz(const std::string &name);
        Buzz(const std::string &name, const std::string &FileName);
        ~Buzz();
        bool speak(const std::string talk);

    protected:
    private:
};

#endif /* !BUZZ_HPP_ */
