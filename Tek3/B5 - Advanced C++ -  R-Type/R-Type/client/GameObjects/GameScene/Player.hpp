/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_PLAYER_HPP
#define RTYPE_PLAYER_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Id.hpp"
#include "client/ECS/SfmlDrawable.hpp"
#include "shared/ECS/Position.hpp"
#include "shared/ECS/Acceleration.hpp"
#include "shared/Network/Requests.hpp"
#include "shared/ECS/Health.hpp"
#include "shared/ECS/Score.hpp"
#include "shared/ECS/WeaponHolder.hpp"
#include "client/Scene/GameScene.hpp"

namespace RType::Client::GameObjects {
    class Player : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlDrawable, RType::ECS::Position, RType::ECS::Acceleration, RType::ECS::Health, RType::ECS::Score, RType::ECS::WeaponHolder> {
    public:
        explicit Player(RType::ECS::ID id, std::shared_ptr<sf::RenderWindow> window, RType::Network::Udp::PlayerID playerId, RType::ECS::Position position, RType::ECS::Acceleration acceleration, RType::ECS::Health health, RType::ECS::Score score, RType::ECS::WeaponHolder weaponHolder, bool isMe) noexcept;
        ~Player() override = default;
        Player(const Player &other) noexcept = delete;
        explicit Player(Player &&other) noexcept = delete;
        Player &operator=(const Player &other) const noexcept = delete;
        Player &operator=(Player &&other) const noexcept = delete;
        [[nodiscard]] bool isMe() const noexcept;
        void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;

    private:
        void updateMove() noexcept;
        void movementByPlayer(const RType::AEvent& event) noexcept;
        [[nodiscard]] bool keyMovement(const RType::AEvent& event) noexcept;
        [[nodiscard]] bool controllerMovement(const RType::AEvent& event) noexcept;
        bool _isMe;
        Clock _clock;
    };
}

#endif //RTYPE_PLAYER_HPP
