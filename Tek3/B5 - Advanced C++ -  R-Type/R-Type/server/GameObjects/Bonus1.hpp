/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_BONUS1_HPP
#define RTYPE_BONUS1_HPP

#include "ABonus.hpp"
#include <iostream>
#include <vector>

namespace RType::Server::GameObjects {
    class Bonus1 : public RType::ECS::ABonus {
    public:
        explicit Bonus1(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Health health, RType::ECS::HitBox hitBox, RType::ECS::State state, RType::ECS::EffectHandler effectHandler) noexcept;
        ~Bonus1() override = default;
        Bonus1(const Bonus1 &other) noexcept = delete;
        explicit Bonus1(Bonus1 &&other) noexcept = delete;
        Bonus1 &operator=(const Bonus1 &other) const noexcept = delete;
        Bonus1 &operator=(Bonus1 &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
    };
}

#endif //RTYPE_BONUS1_HPP
