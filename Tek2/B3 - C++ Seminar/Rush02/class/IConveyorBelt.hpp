/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** IConveyorBelt
*/

#ifndef ICONVEYORBELT_HPP_
#define ICONVEYORBELT_HPP_

#include "Object.hpp"

class IConveyorBelt {
    public:
        virtual ~IConveyorBelt();
        virtual Object *takeObject() = 0;
        virtual bool putObject(Object *object) = 0;
        virtual bool IN() = 0;
        virtual bool OUT() = 0;
    protected:
        Object *_object;
    private:
};

#endif /* !ICONVEYORBELT_HPP_ */
