/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "Position.hpp"

RType::ECS::Position::Position(const int x, const int y) noexcept :  _posX(x), _posY(y) { }

int RType::ECS::Position::getXPos() const noexcept { return _posX; }

int RType::ECS::Position::getYPos() const noexcept { return _posY; }

void RType::ECS::Position::setXPos(int const x) noexcept { _posX = x; }

void RType::ECS::Position::setYPos(int const y) noexcept { _posY = y; }

RType::ECS::Position::Position(const RType::ECS::Position &pos) noexcept : _posX(pos.getXPos()), _posY(pos.getYPos()) { }
