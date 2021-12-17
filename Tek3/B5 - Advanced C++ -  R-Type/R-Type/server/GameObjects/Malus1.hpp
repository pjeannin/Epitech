/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_MALUS1_HPP
#define RTYPE_MALUS1_HPP

#include "AMalus.hpp"
#include <iostream>
#include <vector>

namespace RType::Server::GameObjects {
    class Malus1 : public RType::ECS::AMalus {
    public:
        explicit Malus1(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Health health, RType::ECS::HitBox hitBox, RType::ECS::State state, RType::ECS::EffectHandler effectHandler) noexcept;
        ~Malus1() override = default;
        Malus1(const Malus1 &other) noexcept = delete;
        explicit Malus1(Malus1 &&other) noexcept = delete;
        Malus1 &operator=(const Malus1 &other) const noexcept = delete;
        Malus1 &operator=(Malus1 &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
    };
}

#endif //RTYPE_MALUS1_HPP
