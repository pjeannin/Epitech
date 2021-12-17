/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_AEnemy_HPP
#define RTYPE_AEnemy_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "shared/ECS/Id.hpp"
#include "shared/ECS/Acceleration.hpp"
#include "shared/ECS/Health.hpp"
#include "shared/ECS/HitBox.hpp"
#include "shared/ECS/Score.hpp"
#include "shared/ECS/WeaponHolder.hpp"
#include "shared/ECS/State.hpp"
#include "shared/ECS/EffectHandler.hpp"
#include <iostream>
#include <vector>
#include <shared/Network/Requests.hpp>
#include "shared/Clock/clock.hpp"

namespace RType::ECS {
    class AEnemy : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::Position, RType::ECS::Acceleration, RType::ECS::Health, RType::ECS::HitBox, RType::ECS::WeaponHolder, RType::ECS::State, RType::ECS::EffectHandler> {
    public:
        explicit AEnemy(RType::ECS::ID, RType::ECS::Position, RType::ECS::Acceleration, RType::ECS::Health, RType::ECS::HitBox, RType::ECS::WeaponHolder, RType::ECS::State, RType::ECS::EffectHandler, RType::Network::Udp::EnemyType) noexcept;
        ~AEnemy() override = default;
        AEnemy(const AEnemy &other) noexcept = delete;
        explicit AEnemy(AEnemy &&other) noexcept = delete;
        AEnemy &operator=(const AEnemy &other) const noexcept = delete;
        AEnemy &operator=(AEnemy &&other) const noexcept = delete;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
        [[nodiscard]] RType::Network::Udp::EnemyType getName() const noexcept;

    protected:
        void movementPattern() noexcept;
        RType::Network::Udp::EnemyType _type;
        std::vector<std::pair<int, int>> _pattern;
        size_t _patternMove;
        Clock _clock;
    };
}

#endif //RTYPE_AEnemy_HPP
