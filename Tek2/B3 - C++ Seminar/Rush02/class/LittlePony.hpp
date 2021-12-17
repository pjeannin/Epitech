/*
** EPITECH PROJECT, 2021
** rush2perso
** File description:
** LittlePony
*/

#ifndef LITTLEPONY_HPP_
#define LITTLEPONY_HPP_

#include <iostream>
#include "Toy.hpp"

class LittlePony : public virtual Toy {
    public:
        LittlePony(const std::string &title);
        virtual ~LittlePony();
        void isTaken();
    private:
};

#endif /* !LITTLEPONY_HPP_ */
