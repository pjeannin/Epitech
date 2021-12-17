/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_SETTINGSSCENE_HPP
#define RTYPE_SETTINGSSCENE_HPP

#include "AScene.hpp"
#include "client/Client.hpp"

namespace RType::Client {
    class Client;
    namespace Scene {
        class SettingsScene : public RType::ECS::Scene::AScene {
            public:
                explicit SettingsScene(std::shared_ptr<sf::RenderWindow> window, RType::Client::Client *client) noexcept;
                ~SettingsScene() override = default;
                SettingsScene(const SettingsScene &other) noexcept = delete;
                explicit SettingsScene(SettingsScene &&other) noexcept = delete;
                SettingsScene &operator=(const SettingsScene &other) const noexcept = delete;
                SettingsScene &operator=(SettingsScene &&other) const noexcept = delete;
                void update(const AEvent &event) noexcept override;

            private:
                sf::Font _font;
                RType::Client::Client *_client;
            };
        }
}

#endif //RTYPE_SETTINGSSCENE_HPP
