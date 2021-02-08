/*
** EPITECH PROJECT, 2021
** CPP-RUSH2 [WSL: Ubuntu]
** File description:
** Box
*/

#ifndef BOX_HPP_
#define BOX_HPP_

#include "Object.hpp"
#include "Wrap.hpp"
#include "Toy.hpp"

class Box: virtual public Wrap {
    public:
        explicit Box();
        virtual ~Box();
        void wrapMeThat(Object *object);
        bool getBoxState() const;
        void closeMe();
        Object *openMe();
    protected:
    private:
        bool _isOpen;
};

#endif /* !BOX_HPP_ */
