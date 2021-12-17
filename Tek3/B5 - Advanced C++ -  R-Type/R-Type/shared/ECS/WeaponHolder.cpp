/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#include "WeaponHolder.hpp"

#include <utility>

RType::ECS::WeaponHolder::WeaponHolder(std::shared_ptr<IWeapon> weapon, unsigned int const damage) noexcept : _weapon(std::move(weapon)), _damage{damage} {}

bool RType::ECS::WeaponHolder::hasWeapon() const noexcept { return _weapon != nullptr; }

void RType::ECS::WeaponHolder::setWeapon(std::shared_ptr<IWeapon> const &weapon) noexcept { _weapon = std::move(weapon); }

void RType::ECS::WeaponHolder::setDamage(unsigned int const damage) noexcept { _damage = damage; }

void RType::ECS::WeaponHolder::shot() const noexcept { _weapon->shot(); }

RType::ECS::WeaponHolder::WeaponHolder(const RType::ECS::WeaponHolder &other) noexcept : _weapon(std::move(other.getWeapon())) {}

const std::shared_ptr<RType::ECS::IWeapon> &RType::ECS::WeaponHolder::getWeapon() const noexcept { return _weapon; }

unsigned int RType::ECS::WeaponHolder::getDamage() const noexcept { return _damage; }
