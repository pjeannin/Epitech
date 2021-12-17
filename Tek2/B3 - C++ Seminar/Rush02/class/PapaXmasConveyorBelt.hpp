/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** PapaXmasConveyorBelt
*/

#ifndef PAPAXMASCONVEYORBELT_HPP_
#define PAPAXMASCONVEYORBELT_HPP_

#include "Box.hpp"
#include "GiftPaper.hpp"
#include "IConveyorBelt.hpp"

class PapaXmasConveyorBelt : virtual public IConveyorBelt {
    public:
        explicit PapaXmasConveyorBelt();
        virtual ~PapaXmasConveyorBelt();
        virtual Object *takeObject();
        virtual bool putObject(Object *object);
        virtual bool IN();
        virtual bool OUT();

    protected:
    private:
};

IConveyorBelt *createConveyorBelt();

#endif /* !PAPAXMASCONVEYORBELT_HPP_ */
