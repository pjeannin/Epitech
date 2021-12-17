/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_MAINMENUSCENE_HPP
#define RTYPE_MAINMENUSCENE_HPP

#include "client/Scene/AScene.hpp"
#include "client/GameObjects/Picture.hpp"
#include "client/GameObjects/Menu/NavInfo.hpp"
#include "client/GameObjects/Menu/SpriteSelectionMenuStart.hpp"
#include "client/GameObjects/Music.hpp"
#include "client/Scene/NewGameScene.hpp"
#include "client/GameObjects/Menu/GifWeapon.hpp"
#include "client/GameObjects/Menu/GifTitle.hpp"
#include "client/GameObjects/Text.hpp"
#include "client/GameObjects/GameParallax.hpp"
#include "client/Client.hpp"

namespace RType::Client::Scene {
    class MainMenuScene : public RType::ECS::Scene::AScene {
        public:
            explicit MainMenuScene(std::shared_ptr<sf::RenderWindow> window, RType::Client::Client *client) noexcept;
            ~MainMenuScene() override = default;
            MainMenuScene(const MainMenuScene &other) noexcept = delete;
            explicit MainMenuScene(MainMenuScene &&other) noexcept = delete;
            MainMenuScene &operator=(const MainMenuScene &other) const noexcept = delete;
            MainMenuScene &operator=(MainMenuScene &&other) const noexcept = delete;
            void update(const AEvent &event) noexcept override;

        private:
            sf::Font _font;
            RType::Client::Client *_client;
    };
}

#endif //RTYPE_MAINMENUSCENE_HPP
