/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** MateriaSource
*/

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        _memory[i] = nullptr;
}

MateriaSource::~MateriaSource()
{
}

void MateriaSource::learnMateria(AMateria *materia)
{
    bool can = true;

    for (int i = 0; i < 4; ++i)
        if (_memory[i] && _memory[i]->getType() == materia->getType())
            can = false;
    if (can) {
        for (int i = 0; i < 4; ++i)
            if (_memory[i] == nullptr) {
                _memory[i] = materia;
                return;
            }
    }
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
    for (int i = 0; i < 4; ++i)
        if (_memory[i] && _memory[i]->getType() == type)
            return (_memory[i]->clone());

    return (nullptr);
}