/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_SPRITESELECTIONMENUSTART_HPP
#define RTYPE_SPRITESELECTIONMENUSTART_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "client/ECS/SfmlDrawable.hpp"
#include "shared/ECS/Id.hpp"
#include "client/ECS/SfmlSound.hpp"
#include <iostream>

namespace RType::Client {
    class Client;
    namespace GameObjects {
        class SpriteSelectionMenuStart
                : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlDrawable, RType::ECS::Position, RType::ECS::SfmlSound> {
        public:
            explicit SpriteSelectionMenuStart(RType::ECS::ID id, RType::ECS::SfmlDrawable drawable, RType::ECS::Position position, RType::ECS::SfmlSound hover, RType::Client::Client *client) noexcept;
            ~SpriteSelectionMenuStart() override = default;
            SpriteSelectionMenuStart(const SpriteSelectionMenuStart &other) noexcept = delete;
            explicit SpriteSelectionMenuStart(SpriteSelectionMenuStart &&other) noexcept = delete;
            SpriteSelectionMenuStart &operator=(const SpriteSelectionMenuStart &other) const noexcept = delete;
            SpriteSelectionMenuStart &operator=(SpriteSelectionMenuStart &&other) const noexcept = delete;
            void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects,
                        RType::ECS::IManager *scene) noexcept override;

        private:
            enum Target {
                NEW_GAME = 0,
                SETTINGS = 1,
                TUTORIAL = 2
            };
            int _currentButton;
            RType::Client::Client *_client;
        };
    }
}

#endif //RTYPE_SPRITESELECTIONMENUSTART_HPP
