/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by antonyftp
*/

#include "Player.hpp"

Player::Player(raylib::Vector3 position, Boat::Team const team, unsigned int id, ModelList3D &models) : Boat(position, team, id, models)
{

}

void Player::update(Bombs &bombs, Map *map, std::vector<APowerUp *>&bonus)
{
    Bomb *tmpBomb = nullptr;

    switch (_id) {
        case 1:
            if (IsKeyDown(KEY_W))
                move(UP, map, bonus, bombs);
            else if (IsKeyDown(KEY_A))
                move(LEFT, map, bonus, bombs);
            else if (IsKeyDown(KEY_S))
                move(DOWN, map, bonus, bombs);
            else if (IsKeyDown(KEY_D))
                move(RIGHT, map, bonus, bombs);
            if (IsKeyPressed(KEY_SPACE))
                tmpBomb = placeBomb(_position);
            if (tmpBomb && currentNumberOfBomb(bombs) < _bombMax)
                bombs.push_back(tmpBomb);
            break;
        case 2:
            if (IsKeyDown(KEY_UP))
                move(UP, map, bonus, bombs);
            else if (IsKeyDown(KEY_LEFT))
                move(LEFT, map, bonus, bombs);
            else if (IsKeyDown(KEY_DOWN))
                move(DOWN, map, bonus, bombs);
            else if (IsKeyDown(KEY_RIGHT))
                move(RIGHT, map, bonus, bombs);
            if (IsKeyPressed(KEY_RIGHT_SHIFT))
                tmpBomb = placeBomb(_position);
            if (tmpBomb && currentNumberOfBomb(bombs) < _bombMax)
                bombs.push_back(tmpBomb);
            break;
    }
}
