/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-pierre.jeannin
** File description:
** ToyStory
*/

#ifndef TOYSTORY_HPP_
#define TOYSTORY_HPP_

#include "Toy.hpp"

class ToyStory {
    public:
        ToyStory();
        ~ToyStory();
        static void tellMeAStory(const std::string &fileName, Toy toy1, bool(Toy::*func1)(const std::string), Toy toy2, bool(Toy::*func2)(const std::string));

    protected:
    private:
};

#endif /* !TOYSTORY_HPP_ */
