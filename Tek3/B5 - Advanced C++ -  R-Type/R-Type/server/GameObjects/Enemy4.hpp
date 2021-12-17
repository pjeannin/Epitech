/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_Enemy4_HPP
#define RTYPE_Enemy4_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "shared/ECS/Id.hpp"
#include "shared/ECS/Acceleration.hpp"
#include "shared/ECS/Health.hpp"
#include "shared/ECS/HitBox.hpp"
#include "shared/ECS/Score.hpp"
#include "shared/ECS/WeaponHolder.hpp"
#include "AEnemy.hpp"
#include <iostream>
#include <vector>

namespace RType::Server::GameObjects {
    class Enemy4 : public ECS::AEnemy {
        public:
            explicit Enemy4(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Acceleration acceleration, RType::ECS::Health health, RType::ECS::HitBox hitBox, RType::ECS::WeaponHolder weaponHolder, RType::ECS::State state, RType::ECS::EffectHandler effectHandler) noexcept;
            ~Enemy4() override = default;
            Enemy4(const Enemy4 &other) noexcept = delete;
            explicit Enemy4(Enemy4 &&other) noexcept = delete;
            Enemy4 &operator=(const Enemy4 &other) const noexcept = delete;
            Enemy4 &operator=(Enemy4 &&other) const noexcept = delete;
        protected:
            [[nodiscard]] std::vector<std::pair<int, int>> PatternMovementCreation() noexcept;
    };
}

#endif //RTYPE_Enemy4_HPP
