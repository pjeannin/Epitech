/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** AMateria
*/

#ifndef AMATERIA_HPP_
#define AMATERIA_HPP_

#include <string>
#include "ICharacter.hpp"

class AMateria {
    public:
        AMateria(const std::string &type);
        virtual ~AMateria();
        const std::string &getType() const;
        unsigned int getXP() const;
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);

    protected:
        unsigned int _xp;
        std::string _type;
    private:
};

#endif /* !AMATERIA_HPP_ */
