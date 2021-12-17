/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_AAMMO_HPP
#define RTYPE_AAMMO_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "shared/ECS/Id.hpp"
#include "shared/ECS/Acceleration.hpp"
#include "shared/ECS/Health.hpp"
#include "shared/ECS/HitBox.hpp"
#include "shared/ECS/State.hpp"
#include "shared/ECS/EffectHandler.hpp"
#include "shared/ECS/Dammage.hpp"
#include "shared/Network/Requests.hpp"
#include "shared/Clock/clock.hpp"
#include <iostream>
#include <vector>

namespace RType::ECS {
class AAmmo : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::Position, RType::ECS::Acceleration, RType::ECS::Health, RType::ECS::HitBox, RType::ECS::State, RType::ECS::EffectHandler, RType::ECS::Dammage> {
    public:
        explicit AAmmo(RType::ECS::ID, RType::ECS::Position, RType::ECS::Acceleration, RType::ECS::Health, RType::ECS::HitBox, RType::ECS::State, RType::ECS::EffectHandler, RType::ECS::Dammage, RType::ECS::ID, RType::Network::Udp::AmmoType) noexcept;
        ~AAmmo() override = default;
        AAmmo(const AAmmo &other) noexcept = delete;
        explicit AAmmo(AAmmo &&other) noexcept = delete;
        AAmmo &operator=(const AAmmo &other) const noexcept = delete;
        AAmmo &operator=(AAmmo &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
        [[nodiscard]] virtual RType::Network::Udp::AmmoType getName() const noexcept;
        [[nodiscard]] virtual RType::ECS::ID getSenderId() const noexcept;
    protected:
        RType::ECS::ID _senderId;
        RType::Network::Udp::AmmoType _type;
        Clock _clock;
    };
}

#endif //RTYPE_AAMMO_HPP
