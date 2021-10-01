/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** TODO: add description
*/


#ifndef BOMBERMAN_IBOATCONTROLLER_HPP
#define BOMBERMAN_IBOATCONTROLLER_HPP

#include "../bomb/Bomb.hpp"

#include <vector>

class IBoatController {
public:
    virtual void update(Bombs &bombs, Map *map, std::vector<APowerUp *>&bonus) = 0;
};

#endif //BOMBERMAN_IBOATCONTROLLER_HPP
