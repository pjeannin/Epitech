/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_ABONUS_HPP
#define RTYPE_ABONUS_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "shared/ECS/Id.hpp"
#include "shared/ECS/Acceleration.hpp"
#include "shared/ECS/Health.hpp"
#include "shared/ECS/HitBox.hpp"
#include "shared/ECS/State.hpp"
#include "shared/ECS/EffectHandler.hpp"
#include "shared/Network/Requests.hpp"
#include <iostream>
#include <vector>

namespace RType::ECS {
    class ABonus : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::Position, RType::ECS::Health, RType::ECS::HitBox, RType::ECS::State, RType::ECS::EffectHandler> {
    public:
        explicit ABonus(RType::ECS::ID, RType::ECS::Position, RType::ECS::Health, RType::ECS::HitBox, RType::ECS::State, RType::ECS::EffectHandler, RType::Network::Udp::ObjectType) noexcept;
        ~ABonus() override = default;
        ABonus(const ABonus &other) noexcept = delete;
        explicit ABonus(ABonus &&other) noexcept = delete;
        ABonus &operator=(const ABonus &other) const noexcept = delete;
        ABonus &operator=(ABonus &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
        [[nodiscard]] RType::Network::Udp::ObjectType getName() const noexcept;
    protected:
        RType::Network::Udp::ObjectType _type;
    };
}

#endif //RTYPE_ABONUS_HPP
