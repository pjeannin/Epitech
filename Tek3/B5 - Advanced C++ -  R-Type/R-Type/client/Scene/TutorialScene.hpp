/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_TUTORIALSCENE_HPP
#define RTYPE_TUTORIALSCENE_HPP

#include "AScene.hpp"
#include "client/Client.hpp"

namespace RType::Client {
    class Client;
    namespace Scene {
        class TutorialScene : public RType::ECS::Scene::AScene {
        public:
            explicit TutorialScene(std::shared_ptr<sf::RenderWindow> window, RType::Client::Client *client) noexcept;
            ~TutorialScene() override = default;
            TutorialScene(const TutorialScene &other) noexcept = delete;
            explicit TutorialScene(TutorialScene &&other) noexcept = delete;
            TutorialScene &operator=(const TutorialScene &other) const noexcept = delete;
            TutorialScene &operator=(TutorialScene &&other) const noexcept = delete;
            void update(const AEvent &event) noexcept override;

        private:
            sf::Font _font;
            RType::Client::Client *_client;
        };
    }
}

#endif //RTYPE_TUTORIALSCENE_HPP
