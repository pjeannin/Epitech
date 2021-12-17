/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_BUTTONRETURNCREATEROOM_HPP
#define RTYPE_BUTTONRETURNCREATEROOM_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "client/ECS/SfmlText.hpp"
#include "shared/ECS/HitBox.hpp"
#include "shared/ECS/Id.hpp"
#include "client/Client.hpp"

namespace RType::Client {
    class Client;
    namespace GameObjects {
        class ButtonReturnCreateRoom : public ECS::GameObject<ECS::ID, ECS::Position, ECS::SfmlText> {
        public:
            explicit ButtonReturnCreateRoom(ECS::ID id, ECS::Position position, ECS::SfmlText text, RType::Client::Client *client) noexcept;
            ~ButtonReturnCreateRoom() override = default;
            ButtonReturnCreateRoom(const ButtonReturnCreateRoom &other) noexcept = delete;
            explicit ButtonReturnCreateRoom(ButtonReturnCreateRoom &&other) noexcept = delete;
            ButtonReturnCreateRoom &operator=(const ButtonReturnCreateRoom &other) const noexcept = delete;
            ButtonReturnCreateRoom &operator=(ButtonReturnCreateRoom &&other) const noexcept = delete;
            void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects, RType::ECS::IManager *scene) noexcept override;

        private:
            enum Target {
                NEW_GAME = 0,
            };
            int _currentButton;
            RType::Client::Client *_client;
        };
    }
}

#endif //RTYPE_BUTTONRETURNCREATEROOM_HPP
