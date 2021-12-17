/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_AMALUS_HPP
#define RTYPE_AMALUS_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "shared/ECS/Id.hpp"
#include "shared/ECS/Acceleration.hpp"
#include "shared/ECS/Health.hpp"
#include "shared/ECS/HitBox.hpp"
#include "shared/ECS/State.hpp"
#include "shared/ECS/EffectHandler.hpp"
#include <iostream>
#include <vector>
#include <shared/Network/Requests.hpp>

namespace RType::ECS {
    class AMalus : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::Position, RType::ECS::Health, RType::ECS::HitBox, RType::ECS::State, RType::ECS::EffectHandler> {
    public:
        explicit AMalus(RType::ECS::ID, RType::ECS::Position, RType::ECS::Health, RType::ECS::HitBox, RType::ECS::State, RType::ECS::EffectHandler, RType::Network::Udp::ObjectType) noexcept;
        ~AMalus() override = default;
        AMalus(const AMalus &other) noexcept = delete;
        explicit AMalus(AMalus &&other) noexcept = delete;
        AMalus &operator=(const AMalus &other) const noexcept = delete;
        AMalus &operator=(AMalus &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
        [[nodiscard]] virtual RType::Network::Udp::ObjectType getName() const noexcept;
    protected:
        RType::Network::Udp::ObjectType _type;
    };
}

#endif //RTYPE_AMALUS_HPP
