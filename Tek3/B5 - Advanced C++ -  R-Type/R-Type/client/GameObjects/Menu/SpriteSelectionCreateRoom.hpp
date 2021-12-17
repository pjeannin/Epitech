/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_SPRITESELECTIONCREATEROOM_HPP
#define RTYPE_SPRITESELECTIONCREATEROOM_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "client/ECS/SfmlDrawable.hpp"
#include "shared/ECS/Id.hpp"
#include "client/ECS/SfmlSound.hpp"
#include <iostream>

namespace RType::Client {
    class Client;
    namespace GameObjects {
        class SpriteSelectionCreateRoom
                : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlDrawable, RType::ECS::Position, RType::ECS::SfmlSound> {
        public:
            explicit SpriteSelectionCreateRoom(RType::ECS::ID id, RType::ECS::SfmlDrawable drawable, RType::ECS::Position position, RType::ECS::SfmlSound hover, RType::Client::Client *client) noexcept;
            ~SpriteSelectionCreateRoom() override = default;
            SpriteSelectionCreateRoom(const SpriteSelectionCreateRoom &other) noexcept = delete;
            explicit SpriteSelectionCreateRoom(SpriteSelectionCreateRoom &&other) noexcept = delete;
            SpriteSelectionCreateRoom &operator=(const SpriteSelectionCreateRoom &other) const noexcept = delete;
            SpriteSelectionCreateRoom &operator=(SpriteSelectionCreateRoom &&other) const noexcept = delete;
            void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects,
                        RType::ECS::IManager *scene) noexcept override;

        private:
            enum Target {
                READY = 0,
                STARTGAME = 1,
            };
            int _currentButton;
            RType::Client::Client *_client;
            bool _validate;
        };
    }
}

#endif //RTYPE_SPRITESELECTIONCREATEROOM_HPP
