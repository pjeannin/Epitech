/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** PapaXmasElf
*/

#ifndef PAPAXMASELF_HPP_
#define PAPAXMASELF_HPP_

#include "PapaXmasTable.hpp"
#include "PapaXmasConveyorBelt.hpp"
#include "IElf.hpp"
#include "Toy.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

class PapaXmasElf : public virtual IElf {
    public:
        PapaXmasElf(const std::string name);
        ~PapaXmasElf();
        void wrap(Object *object);

    protected:
    private:
        std::string _name;
        IConveyorBelt *_conveyerBelt;
        ITable *_table;
        Object *_object;

};

#endif /* !PAPAXMASELF_HPP_ */
