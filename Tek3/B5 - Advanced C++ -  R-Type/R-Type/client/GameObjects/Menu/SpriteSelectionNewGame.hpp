/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_SPRITESELECTIONNEWGAME_HPP
#define RTYPE_SPRITESELECTIONNEWGAME_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "client/ECS/SfmlDrawable.hpp"
#include "shared/ECS/Id.hpp"
#include <iostream>
#include "client/ECS/SfmlSound.hpp"
#include "client/Client.hpp"

namespace RType::Client {
    class Client;
    namespace GameObjects {
        class SpriteSelectionNewGame
                : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlDrawable, RType::ECS::Position, RType::ECS::SfmlSound> {
        public:
            explicit SpriteSelectionNewGame(RType::ECS::ID id, RType::ECS::SfmlDrawable drawable,
                                            RType::ECS::Position position, RType::ECS::SfmlSound hover,
                                            RType::Client::Client *client) noexcept;
            ~SpriteSelectionNewGame() override = default;
            SpriteSelectionNewGame(const SpriteSelectionNewGame &other) noexcept = delete;
            explicit SpriteSelectionNewGame(SpriteSelectionNewGame &&other) noexcept = delete;
            SpriteSelectionNewGame &operator=(const SpriteSelectionNewGame &other) const noexcept = delete;
            SpriteSelectionNewGame &operator=(SpriteSelectionNewGame &&other) const noexcept = delete;
            void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects,
                        RType::ECS::IManager *scene) noexcept override;

        private:
            enum Target {
                JOIN = 0,
                CREATE = 1
            };
            int _currentButton;
            std::string _pseudo;
            RType::Client::Client *_client;
        };
    }
}

#endif //RTYPE_SPRITESELECTIONNEWGAME_HPP
