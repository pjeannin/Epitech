/*
** EPITECH PROJECT, 2021
** PROJECT NAME
** File description:
** DESCRIPTION
*/

#ifndef RTYPE_PLAYER_HPP
#define RTYPE_PLAYER_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "shared/ECS/Id.hpp"
#include "shared/ECS/Acceleration.hpp"
#include "shared/ECS/Health.hpp"
#include "shared/ECS/HitBox.hpp"
#include "shared/ECS/Score.hpp"
#include "shared/ECS/WeaponHolder.hpp"
#include "shared/ECS/EffectHandler.hpp"
#include <iostream>
#include <vector>

namespace RType::Server {
    class Server;
    namespace GameObjects {
        class Player : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::Position, RType::ECS::Acceleration, RType::ECS::Health, RType::ECS::HitBox, RType::ECS::Score, RType::ECS::WeaponHolder, RType::ECS::EffectHandler> {
        public:
            explicit Player(RType::ECS::ID id, RType::ECS::Position position, RType::ECS::Acceleration acceleration, RType::ECS::Health health, RType::ECS::HitBox hitBox, RType::ECS::Score score, RType::ECS::WeaponHolder weaponHolder, RType::ECS::EffectHandler effectHandler) noexcept;
            ~Player() override = default;
            Player(const Player &other) noexcept = delete;
            explicit Player(Player &&other) noexcept = delete;
            Player &operator=(const Player &other) const noexcept = delete;
            Player &operator=(Player &&other) const noexcept = delete;
            void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;
            [[nodiscard]] std::string getName() noexcept;
            void setName(const std::string& name) noexcept;

            uint32_t id;
        private:
            RType::Server::Server *_server;
            std::string _name;
        };
    }
}

#endif //RTYPE_PLAYER_HPP
