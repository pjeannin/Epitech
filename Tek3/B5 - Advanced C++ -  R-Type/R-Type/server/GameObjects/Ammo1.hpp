/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_AMMO1_HPP
#define RTYPE_AMMO1_HPP

#include "AAmmo.hpp"
#include <iostream>
#include <vector>

namespace RType::Client::GameObjects {
    class Ammo1 : public RType::ECS::AAmmo {
    public:
        explicit Ammo1(RType::ECS::ID, RType::ECS::Position, RType::ECS::Acceleration, RType::ECS::Health, RType::ECS::HitBox, RType::ECS::State, RType::ECS::EffectHandler, RType::ECS::Dammage, RType::ECS::ID) noexcept;
        ~Ammo1() override = default;
        Ammo1(const Ammo1 &other) noexcept = delete;
        explicit Ammo1(Ammo1 &&other) noexcept = delete;
        Ammo1 &operator=(const Ammo1 &other) const noexcept = delete;
        Ammo1 &operator=(Ammo1 &&other) const noexcept = delete;
    };
}

#endif //RTYPE_AMMO1_HPP
