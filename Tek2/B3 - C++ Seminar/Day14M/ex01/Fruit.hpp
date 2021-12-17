/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD14M-pierre.jeannin
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <string>

class Fruit {
    public:
        virtual ~Fruit();
        int getVitamins() const;
        const std::string &getName() const;
        Fruit(const std::string &name, int vitamines);

    protected:
        Fruit();
        std::string _name;
        int _vitamins;
    private:
};

#endif /* !FRUIT_HPP_ */
