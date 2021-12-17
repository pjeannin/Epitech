/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_Enemy1_HPP
#define RTYPE_Enemy1_HPP

#include "AEnemy.hpp"
#include <iostream>
#include <vector>

namespace RType::Server::GameObjects {
    class Enemy1 : public RType::ECS::AEnemy {
        public:
            explicit Enemy1(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Acceleration acceleration, RType::ECS::Health health, RType::ECS::HitBox hitBox, RType::ECS::WeaponHolder weaponHolder, RType::ECS::State state, RType::ECS::EffectHandler effectHandler) noexcept;
            ~Enemy1() override = default;
            Enemy1(const Enemy1 &other) noexcept = delete;
            explicit Enemy1(Enemy1 &&other) noexcept = delete;
            Enemy1 &operator=(const Enemy1 &other) const noexcept = delete;
            Enemy1 &operator=(Enemy1 &&other) const noexcept = delete;
        protected:
            [[nodiscard]] std::vector<std::pair<int, int>> PatternMovementCreation() noexcept;
    };
}

#endif //RTYPE_Enemy1_HPP
