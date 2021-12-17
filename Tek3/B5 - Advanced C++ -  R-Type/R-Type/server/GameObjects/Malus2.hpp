/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_MALUS2_HPP
#define RTYPE_MALUS2_HPP

#include "AMalus.hpp"
#include <iostream>
#include <vector>

namespace RType::Server::GameObjects {
    class Malus2 : public RType::ECS::AMalus {
    public:
        explicit Malus2(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Health health, RType::ECS::HitBox hitBox, RType::ECS::State state, RType::ECS::EffectHandler effectHandler) noexcept;
        ~Malus2() override = default;
        Malus2(const Malus2 &other) noexcept = delete;
        explicit Malus2(Malus2 &&other) noexcept = delete;
        Malus2 &operator=(const Malus2 &other) const noexcept = delete;
        Malus2 &operator=(Malus2 &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
    };
}

#endif //RTYPE_MALUS2_HPP
