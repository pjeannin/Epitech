/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** TODO: add description
*/

#ifndef RTYPE_TUTORIALSCENE_HPP
#define RTYPE_TUTORIALSCENE_HPP

#include "AGameManager.hpp"
#include "shared/ECS/IEffect.hpp"
#include "shared/ECS/State.hpp"
#include "shared/ECS/Health.hpp"
#include "shared/ECS/HitBox.hpp"
#include "shared/ECS/Score.hpp"
#include "shared/ECS/EffectHandler.hpp"
#include "shared/ECS/Id.hpp"

namespace RType::Server {
    class Server;
class Game : public RType::Server::AGameManager {
    public:
        explicit Game(RType::Server::Server *server) noexcept;
        ~Game() override = default;
        Game(const Game &other) noexcept = delete;
        explicit Game(Game &&other) noexcept = delete;
        Game &operator=(const Game &other) const noexcept = delete;
        Game &operator=(Game &&other) const noexcept = delete;
        void update() noexcept override;
        void checkDeath() noexcept;
        void checkCollide() noexcept;
    private:
        void checkCollideNext(int i, int j) noexcept;
        void removeCollide(int i, int j) noexcept;
        RType::Server::Server *_server;
        std::vector<std::shared_ptr<RType::ECS::IGameObject>> _collideA;
        std::vector<std::shared_ptr<RType::ECS::IGameObject>> _collideB;
    };
}

#endif //RTYPE_TUTORIALSCENE_HPP
