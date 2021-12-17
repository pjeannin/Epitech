/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_BONUS2_HPP
#define RTYPE_BONUS2_HPP

#include "ABonus.hpp"
#include <iostream>
#include <vector>

namespace RType::Server::GameObjects {
    class Bonus2 : public RType::ECS::ABonus {
    public:
        explicit Bonus2(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Health health, RType::ECS::HitBox hitBox, RType::ECS::State state, RType::ECS::EffectHandler effectHandler) noexcept;
        ~Bonus2() override = default;
        Bonus2(const Bonus2 &other) noexcept = delete;
        explicit Bonus2(Bonus2 &&other) noexcept = delete;
        Bonus2 &operator=(const Bonus2 &other) const noexcept = delete;
        Bonus2 &operator=(Bonus2 &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
    };
}

#endif //RTYPE_BONUS2_HPP
