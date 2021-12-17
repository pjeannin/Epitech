/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#include "Dammage.hpp"

RType::ECS::Dammage::Dammage(const int damage) noexcept :  _damage(damage) { }

int RType::ECS::Dammage::getDamage() const noexcept { return _damage; }

void RType::ECS::Dammage::setDamage(int const damage) noexcept { _damage = damage; }

RType::ECS::Dammage::Dammage(const RType::ECS::Dammage &other) noexcept : _damage(other.getDamage()) { }
