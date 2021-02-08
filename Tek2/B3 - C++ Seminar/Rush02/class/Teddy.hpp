/*
** EPITECH PROJECT, 2021
** rush2perso
** File description:
** Teddy
*/

#ifndef TEDDY_HPP_
#define TEDDY_HPP_

#include <iostream>
#include "Toy.hpp"

class Teddy : public virtual Toy {
    public:
        Teddy(const std::string &title);
        ~Teddy();
        void isTaken();
};

#endif /* !TEDDY_HPP_ */
