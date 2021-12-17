/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_Enemy3_HPP
#define RTYPE_Enemy3_HPP

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

namespace RType::Client::GameObjects {
    class Enemy3 : public ECS::AEnemy {
    public:
        explicit Enemy3(RType::ECS::ID, RType::ECS::Position, RType::ECS::Acceleration, RType::ECS::SfmlDrawable) noexcept;
        ~Enemy3() override = default;
        Enemy3(const Enemy3 &other) noexcept = delete;
        explicit Enemy3(Enemy3 &&other) noexcept = delete;
        Enemy3 &operator=(const Enemy3 &other) const noexcept = delete;
        Enemy3 &operator=(Enemy3 &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
    };
}

#endif //RTYPE_Enemy3_HPP
