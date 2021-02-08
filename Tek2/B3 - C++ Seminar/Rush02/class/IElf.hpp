/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** IElf
*/

#ifndef IELF_HPP_
#define IELF_HPP_

#include "Wrap.hpp"

class IElf {
    public:
        virtual ~IElf();
        virtual void wrap(Object *object) = 0;

    protected:
    private:
};

#endif /* !IELF_HPP_ */
