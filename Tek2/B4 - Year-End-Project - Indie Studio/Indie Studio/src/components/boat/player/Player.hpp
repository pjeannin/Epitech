/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by antonyftp
*/

#ifndef BOMBERMAN_PLAYER_HPP
#define BOMBERMAN_PLAYER_HPP

#include "../Boat.hpp"
#include "../IBoatController.hpp"
#include "../../bomb/Bomb.hpp"
#include "../../../../include/Include.hpp"

class Player : public Boat {
    public:
        explicit Player(raylib::Vector3 position, Boat::Team const team, unsigned  int id, ModelList3D &models);
        ~Player() = default;

    void update(Bombs &bombs, Map *map, std::vector<APowerUp *>&bonus) override;
    private:

};

#endif //BOMBERMAN_PLAYER_HPP
