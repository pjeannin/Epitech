/*
** EPITECH PROJECT, 2021
** rush2perso
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Object.hpp"

class Toy : public virtual Object {
    public:
        Toy(const std::string &title);
        virtual ~Toy();
        bool getToyStatus() const;
        virtual void isTaken() = 0;
    protected:
        bool _isTaken;
};

#endif /* !TOY_HPP_ */
