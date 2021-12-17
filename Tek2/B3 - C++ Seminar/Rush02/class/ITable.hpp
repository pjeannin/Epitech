/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** ITable
*/

#ifndef ITABLE_HPP_
#define ITABLE_HPP_

#include "Object.hpp"

class ITable {
    public:
        virtual ~ITable();
        virtual Object *takeObject(int pos) = 0;
        virtual bool putObject(Object *object) = 0;
        virtual std::string *look() = 0;
    private:
};

#endif /* !ITABLE_HPP_ */
