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

namespace RType::Client::GameObjects {
    class Enemy1 : public RType::ECS::AEnemy {
        public:
            explicit Enemy1(RType::ECS::ID, RType::ECS::Position, RType::ECS::Acceleration, RType::ECS::SfmlDrawable) noexcept;
            ~Enemy1() override = default;
            Enemy1(const Enemy1 &other) noexcept = delete;
            explicit Enemy1(Enemy1 &&other) noexcept = delete;
            Enemy1 &operator=(const Enemy1 &other) const noexcept = delete;
            Enemy1 &operator=(Enemy1 &&other) const noexcept = delete;
            void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
    };
}

#endif //RTYPE_Enemy1_HPP
