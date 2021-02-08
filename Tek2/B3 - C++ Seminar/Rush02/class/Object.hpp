/*
** EPITECH PROJECT, 2021
** rush2perso
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>

class Object {
    public:
        explicit Object(const std::string &title, const std::string &type);
        virtual ~Object();
        const std::string &getTitle() const;
        const std::string &getType() const;
    protected:
        std::string _title;
        std::string _type;
};

std::ostream& operator<<(std::ostream &stream, Object const &object);

#endif /* !OBJECT_HPP_ */