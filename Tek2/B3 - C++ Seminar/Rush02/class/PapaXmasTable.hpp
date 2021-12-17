/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** PapaXmasTable
*/

#ifndef PAPAXMASTABLE_HPP_
#define PAPAXMASTABLE_HPP_

#include "ITable.hpp"

class PapaXmasTable : virtual public ITable {
    public:
        explicit PapaXmasTable();
        virtual ~PapaXmasTable();
        Object *takeObject(int pos);
        bool putObject(Object *object);
        std::string *look();

    protected:
        Object *_object[10];
    private:
};

ITable *createTable();

#endif /* !PAPAXMASTABLE_HPP_ */
