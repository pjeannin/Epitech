/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-pierre.jeannin
** File description:
** Ratatouille
*/

#ifndef RATATOUILLE_HPP_
#define RATATOUILLE_HPP_

#include <string>
#include <sstream>

class Ratatouille {
    public:
        Ratatouille();
        Ratatouille(const Ratatouille &other);
        ~Ratatouille();
        Ratatouille &operator=(const Ratatouille &other);
        Ratatouille &addVegetable(unsigned char c);
        Ratatouille &addCondiment(unsigned int i);
        Ratatouille &addSpice(double d);
        Ratatouille &addSauce(const std::string &s);
        std::string kooc();

    protected:
    private:
        std::stringstream _ratatouille;
};

#endif /* !RATATOUILLE_HPP_ */
