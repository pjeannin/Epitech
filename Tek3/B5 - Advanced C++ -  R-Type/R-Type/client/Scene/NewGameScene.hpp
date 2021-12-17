/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_NEWGAMESCENE_HPP
#define RTYPE_NEWGAMESCENE_HPP

#include "AScene.hpp"
#include "client/Client.hpp"

namespace RType::Client {
    class Client;
    namespace Scene {
        class NewGameScene : public RType::ECS::Scene::AScene {
        public:
            explicit NewGameScene(std::shared_ptr<sf::RenderWindow> window, RType::Client::Client *client) noexcept;
            ~NewGameScene() override = default;
            NewGameScene(const NewGameScene &other) noexcept = delete;
            explicit NewGameScene(NewGameScene &&other) noexcept = delete;
            NewGameScene &operator=(const NewGameScene &other) const noexcept = delete;
            NewGameScene &operator=(NewGameScene &&other) const noexcept = delete;
            void update(const AEvent &event) noexcept override;

        private:
            sf::Font _font;
            RType::Client::Client *_client;
        };
    }
}

#endif //RTYPE_NEWGAMESCENE_HPP
