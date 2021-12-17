/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_BONUS3_HPP
#define RTYPE_BONUS3_HPP

#include "ABonus.hpp"
#include <iostream>
#include <vector>

namespace RType::Server::GameObjects {
    class Bonus3 : public RType::ECS::ABonus {
    public:
        explicit Bonus3(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Health health, RType::ECS::HitBox hitBox, RType::ECS::State state, RType::ECS::EffectHandler effectHandler) noexcept;
        ~Bonus3() override = default;
        Bonus3(const Bonus3 &other) noexcept = delete;
        explicit Bonus3(Bonus3 &&other) noexcept = delete;
        Bonus3 &operator=(const Bonus3 &other) const noexcept = delete;
        Bonus3 &operator=(Bonus3 &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
    };
}

#endif //RTYPE_BONUS3_HPP
