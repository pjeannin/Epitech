/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_BUTTONRETURNSETTINGS_HPP
#define RTYPE_BUTTONRETURNSETTINGS_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "client/ECS/SfmlText.hpp"
#include "shared/ECS/HitBox.hpp"
#include "shared/ECS/Id.hpp"
#include "client/Client.hpp"

namespace RType::Client {
    class Client;
    namespace GameObjects {
        class ButtonReturnSettings : public ECS::GameObject<ECS::ID, ECS::Position, ECS::SfmlText> {
        public:
            explicit ButtonReturnSettings(ECS::ID id, ECS::Position position, ECS::SfmlText text, RType::Client::Client *client) noexcept;
            ~ButtonReturnSettings() override = default;
            ButtonReturnSettings(const ButtonReturnSettings &other) noexcept = delete;
            explicit ButtonReturnSettings(ButtonReturnSettings &&other) noexcept = delete;
            ButtonReturnSettings &operator=(const ButtonReturnSettings &other) const noexcept = delete;
            ButtonReturnSettings &operator=(ButtonReturnSettings &&other) const noexcept = delete;
            void update(const AEvent &event, std::vector<std::shared_ptr<RType::ECS::IGameObject>> &gameObjects,
                        RType::ECS::IManager *scene) noexcept override;

        private:
            enum Target {
                MAIN_MENU = 0,
            };
            int _currentButton;
            RType::Client::Client *_client;
        };
    }
}

#endif //RTYPE_BUTTONRETURNSETTINGS_HPP
