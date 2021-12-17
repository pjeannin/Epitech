/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "Id.hpp"

RType::ECS::ID::ID(unsigned short id) noexcept : _id(id) { }

RType::ECS::ID::ID(const RType::ECS::ID &other) noexcept : _id(other._id) { }

unsigned short RType::ECS::ID::getId() const noexcept { return _id; }
