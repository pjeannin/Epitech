/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "Health.hpp"

RType::ECS::Health::Health(unsigned short const defaultHealth) noexcept : _health(defaultHealth), _defaultHealth(defaultHealth) {}

int RType::ECS::Health::getHealth() const noexcept { return _health; }

void RType::ECS::Health::removeHealth(unsigned short const toRemove) noexcept {
    if ((_health -= toRemove) < 0)
        _health = 0;
}

void RType::ECS::Health::addHealth(unsigned short const toAdd) noexcept {
    if ((_health += toAdd) > _defaultHealth)
        _health = _defaultHealth;
}

RType::ECS::Health::Health(const RType::ECS::Health &other) noexcept : _health(other.getHealth()), _defaultHealth(other.getDefaultHealth()) { }

int RType::ECS::Health::getDefaultHealth() const noexcept { return _defaultHealth; }

void RType::ECS::Health::setHealth(const unsigned short health) noexcept { _health = health; }
