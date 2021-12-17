/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Acceleration
*/

#include "Acceleration.hpp"

RType::ECS::Acceleration::Acceleration(int const x, int const y) noexcept : _accelerationX(x), _accelerationY(y) {}

int RType::ECS::Acceleration::getXAcceleration() const noexcept { return _accelerationX; }

int RType::ECS::Acceleration::getYAcceleration() const noexcept { return _accelerationY; }

void RType::ECS::Acceleration::setXAcceleration(int const x) noexcept { _accelerationX = x; }

void RType::ECS::Acceleration::setYAcceleration(int const y) noexcept { _accelerationY = y; }

RType::ECS::Acceleration::Acceleration(const RType::ECS::Acceleration &other) noexcept : _accelerationX(other.getXAcceleration()), _accelerationY(other.getYAcceleration()) { }
