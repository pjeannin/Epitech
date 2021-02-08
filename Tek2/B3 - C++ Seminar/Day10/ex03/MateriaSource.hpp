/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** MateriaSource
*/

#ifndef MATERIASOURCE_HPP_
#define MATERIASOURCE_HPP_

#include <map>
#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
    public:
        MateriaSource();
        ~MateriaSource();
        void learnMateria(AMateria *materia);
        AMateria *createMateria(const std::string &type);

    protected:
    private:
        AMateria *_memory[4];
};

#endif /* !MATERIASOURCE_HPP_ */
