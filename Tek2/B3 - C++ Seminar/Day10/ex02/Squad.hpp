/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD10-pierre.jeannin
** File description:
** Squad
*/

#ifndef SQUAD_HPP_
#define SQUAD_HPP_

#include <vector>
#include "ISquad.hpp"

class Squad : public ISquad {
    public:
        Squad();
        Squad(const Squad &squad);
        ~Squad();
        int getCount() const;
        ISpaceMarine* getUnit(int position);
        int push(ISpaceMarine*);
        Squad &operator=(const Squad &squad);

    protected:
    private:
        std::vector<ISpaceMarine *> _squad;
};

#endif /* !SQUAD_HPP_ */
