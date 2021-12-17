/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_BUTTONRETURNTUTORIAL_HPP
#define RTYPE_BUTTONRETURNTUTORIAL_HPP

#include "shared/ECS/GameObject.hpp"
#include "shared/ECS/Position.hpp"
#include "client/ECS/SfmlText.hpp"
#include "shared/ECS/HitBox.hpp"
#include "shared/ECS/Id.hpp"
#include "client/Client.hpp"

namespace RType::Client {
    class Client;

    namespace GameObjects {
        class ButtonReturnTutorial : public ECS::GameObject<ECS::ID, ECS::Position, ECS::SfmlText> {
        public:
            explicit ButtonReturnTutorial(ECS::ID id, ECS::Position position, ECS::SfmlText text, RType::Client::Client *client) noexcept;
            ~ButtonReturnTutorial() override = default;
            ButtonReturnTutorial(const ButtonReturnTutorial &other) noexcept = delete;
            explicit ButtonReturnTutorial(ButtonReturnTutorial &&other) noexcept = delete;
            ButtonReturnTutorial &operator=(const ButtonReturnTutorial &other) const noexcept = delete;
            ButtonReturnTutorial &operator=(ButtonReturnTutorial &&other) const noexcept = delete;
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

#endif //RTYPE_BUTTONRETURNTUTORIAL_HPP
