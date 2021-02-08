/*
** EPITECH PROJECT, 2021
** CPP-RUSH2 [WSL: Ubuntu]
** File description:
** ConveyorBeltRand
*/

#ifndef CONVEYORBELTRAND_HPP_
#define CONVEYORBELTRAND_HPP_
#include "IConveyorBelt.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

class ConveyorBeltRand : IConveyorBelt {
    public:
        ConveyorBeltRand();
        ~ConveyorBeltRand();
        virtual bool IN();
    protected:
};

#endif /* !CONVEYORBELTRAND_HPP_ */
