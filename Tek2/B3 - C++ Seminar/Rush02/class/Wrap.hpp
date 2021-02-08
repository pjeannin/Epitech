/*
** EPITECH PROJECT, 2021
** CPP-RUSH2 [WSL: Ubuntu]
** File description:
** Wrap
*/

#ifndef WRAP_HPP_
#define WRAP_HPP_

#include "Object.hpp"

class Wrap : public virtual Object {
    public:
        explicit Wrap(const std::string &type);
        virtual ~Wrap();
        virtual void wrapMeThat(Object *object);
        virtual Object *openMe();
        virtual void closeMe() = 0;
        virtual bool isEmpty() const;
        virtual void isTaken();
    protected:
        bool _isTaken;
        Object *_object;
        std::string _type;
};

#endif /* !WRAP_HPP_ */
