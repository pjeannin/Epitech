/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_SPRITESELECTIONJOINROOM_HPP
#define RTYPE_SPRITESELECTIONJOINROOM_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "client/ECS/SfmlDrawable.hpp"
#include "shared/ECS/Id.hpp"
#include "client/ECS/SfmlSound.hpp"
#include <iostream>

namespace RType::Client {
    class Client;
    namespace GameObjects {
        class SpriteSelectionJoinRoom
                : public RType::ECS::GameObject<RType::ECS::ID, RType::ECS::SfmlDrawable, RType::ECS::Position, RType::ECS::SfmlSound> {
        public:
            explicit SpriteSelectionJoinRoom(RType::ECS::ID id, RType::ECS::SfmlDrawable drawable, RType::ECS::Position position, RType::ECS::SfmlSound hover, RType::Client::Client *client) noexcept;
            ~SpriteSelectionJoinRoom() override = default;
            SpriteSelectionJoinRoom(const SpriteSelectionJoinRoom &other) noexcept = delete;
            explicit SpriteSelectionJoinRoom(SpriteSelectionJoinRoom &&other) noexcept = delete;
            SpriteSelectionJoinRoom &operator=(const SpriteSelectionJoinRoom &other) const noexcept = delete;
            SpriteSelectionJoinRoom &operator=(SpriteSelectionJoinRoom &&other) const noexcept = delete;
            void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects,
                        RType::ECS::IManager *scene) noexcept override;

        private:
            enum Target {
                JOINROOM = 0,
                READY = 1,
            };
            int _currentButton;
            RType::Client::Client *_client;
            bool _validate;
            bool _validateRoom;
        };
    }
}

#endif //RTYPE_SPRITESELECTIONJOINROOM_HPP
